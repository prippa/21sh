/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:50:16 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 18:57:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_characters.h"
#include "auto_completion.h"
#include "environ_manipulation.h"
#include "info.h"

static void		rl_t_manage_tilde(char **path)
{
	const char	*home;
	char		*new_path;

	if ((home = env_get_vlu_by_key(sh()->env.start, HOME_ENV)))
	{
		new_path = ft_strdup(home);
		ft_strjoin_free(&new_path, *path + 1,
			ft_strlen(new_path), ft_strlen(*path + 1));
		ft_strdel(path);
		*path = new_path;
	}
}

static t_bool	rl_t_check_path_access(const char *path)
{
	char		*as_path;
	t_bool		res;

	res = true;
	if ((as_path = ft_strrchr(path, UNIX_PATH_SEPARATOR)))
	{
		as_path = ft_strsub(path, 0, as_path - path + 1);
		if (access(as_path, F_OK) == ERR)
			res = false;
	}
	ft_strdel(&as_path);
	return (res);
}

static t_bool	rl_t_get_path_from_line(t_line *ln, char **path)
{
	size_t	len;
	size_t	size;

	size = ln->pc;
	len = 0;
	while (size--)
	{
		if (ft_isspace(ln->line[size]))
			break ;
		++len;
	}
	*path = ft_strsub(ln->line, ln->pc - len, len);
	if (**path == TILDE_C)
		rl_t_manage_tilde(path);
	return (rl_t_check_path_access(*path));
}

static t_bool	rl_t_get_cmd_from_line(t_line *ln, char **cmd)
{
	size_t	len;
	size_t	size;
	t_bool	space_flag;

	size = ln->pc;
	space_flag = false;
	len = 0;
	while (size--)
	{
		if (ln->line[size] == SEMICOLON_C || ln->line[size] == PIPE_C)
			break ;
		if (ft_isspace(ln->line[size]))
			space_flag = true;
		else if (space_flag && ft_isascii(ln->line[size]))
			return (false);
		if (!space_flag)
			++len;
	}
	*cmd = ft_strsub(ln->line, ln->pc - len, len);
	return (true);
}

t_ac			*ac(void)
{
	static t_ac		ac;

	return (&ac);
}

int32_t			rl_ke_tab(t_line *ln)
{
	char	*match_str;
	t_list	matches;
	int32_t	res;

	res = ERR;
	matches.start = NULL;
	match_str = NULL;
	if (rl_t_get_cmd_from_line(ln, &match_str))
		matches = rl_t_get_cmd_matches(match_str);
	if (!matches.start)
	{
		ft_strdel(&match_str);
		if (rl_t_get_path_from_line(ln, &match_str))
			matches = rl_t_get_path_matches(&match_str);
	}
	if (matches.start)
	{
		res = tab_process_matches(matches.start, ft_strlen(match_str), ln);
		LST_DEL(&matches);
	}
	ft_strdel(&match_str);
	return (res);
}
