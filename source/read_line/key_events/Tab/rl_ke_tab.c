/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:50:16 by prippa            #+#    #+#             */
/*   Updated: 2019/03/08 10:50:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "syntax_characters.h"
#include "builtin_static_box.h"
#include "environ_manipulation.h"
#include "messages.h"
#include "button_keys.h"
#include "line_syntax.h"

static void		rl_t_gm_push_cmd(t_list *m, const char *bc, const char *c)
{
	char	*cmd;

	if (ft_strnequ(bc, c, ft_strlen(bc)))
	{
		cmd = ft_strdup(c);
		LST_PUSH_BACK_REF(m, cmd, ft_strlen(cmd));
	}
}

static void		rl_t_read_dir(t_list *m, char **paths, const char *bc)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*bin;

	--paths;
	while (*(++paths))
	{
		if (access(*paths, F_OK) || access(*paths, X_OK))
			continue ;
		if (!(dip = opendir(*paths)))
			g_fef(OPENDIR_FAILED);
		while ((dit = readdir(dip)))
		{
			bin = ft_strjoin(*paths, (char[2]){UNIX_PATH_SEPARATOR, 0});
			ft_strjoin_free(&bin, dit->d_name,
				ft_strlen(bin), ft_strlen(dit->d_name));
			if (!access(bin, X_OK) && dit->d_type != DT_DIR)
				rl_t_gm_push_cmd(m, bc, dit->d_name);
			ft_strdel(&bin);
		}
		if ((closedir(dip)) == ERR)
			g_fef(CLOSEDIR_FAILED);
	}
}

static t_list	rl_t_get_matches(const char *bc)
{
	size_t	i;
	t_list	m;
	char	**paths;
	char	*path_env;

	LST_INIT(&m, &ft_cnt_delptr);
	i = -1;
	while (++i < SH_BUILTIN_SIZE)
		rl_t_gm_push_cmd(&m, bc, g_builtin_box[i].s);
	if (!(path_env = env_get_vlu_by_key(sh()->env.start, PATH_ENV)))
		path_env = CUR_DIR;
	paths = ft_strsplit(path_env, PATH_ENV_SEPARATOR);
	rl_t_read_dir(&m, paths, bc);
	ft_arrdel(&paths);
	return (m);
}

static char		*rl_t_get_cmd_from_line(t_line *ln)
{
	char	*cmd;
	size_t	len;
	size_t	size;
	t_bool	space_flag;

	size = ln->pc;
	space_flag = false;
	len = 0;
	while (size--)
	{
		if (ln->line[size] == SEMICOLON_C)
			break ;
		if (ft_isspace(ln->line[size]))
			space_flag = true;
		else if (space_flag && ft_isascii(ln->line[size]))
			return (NULL);
		if (!space_flag)
			++len;
	}
	cmd = ft_strsub(ln->line, ln->pc - len, len);
	return (cmd);
}

int32_t			rl_ke_tab(t_line *ln)
{
	char	*base_cmd;
	t_list	matches;
	int32_t	res;

	res = ERR;
	if (rl()->inhibitors_in_use && rl()->inhibitors_in_use < LS_SLASH)
		return (res);
	if (!(base_cmd = rl_t_get_cmd_from_line(ln)))
		return (res);
	matches = rl_t_get_matches(base_cmd);
	if (matches.start)
	{
		res = tab_process_matches(matches.start, ft_strlen(base_cmd), ln);
		LST_DEL(&matches);
	}
	ft_strdel(&base_cmd);
	return (res);
}
