/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:50:16 by prippa            #+#    #+#             */
/*   Updated: 2019/04/28 11:54:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_characters.h"
#include "auto_completion.h"

static t_bool	rl_t_get_path_from_line(t_line *ln, char **path)
{
	size_t	len;
	size_t	size;

	size = ln->pc;
	len = 0;
	while (size--)
	{
		if (ln->line[size] == SPACE_C)
			break ;
		++len;
	}
	*path = ft_strsub(ln->line, ln->pc - len, len);
	return (true);
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
		if (ln->line[size] == SEMICOLON_C)
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

int32_t			rl_ke_tab(t_line *ln)
{
	char	*match_str;
	t_list	matches;
	int32_t	res;

	res = ERR;
	if (rl_t_get_cmd_from_line(ln, &match_str))
		matches = rl_t_get_cmd_matches(match_str);
	else if (rl_t_get_path_from_line(ln, &match_str))
		matches = rl_t_get_path_matches(match_str);
	else
		return (res);
	if (matches.start)
	{
		res = tab_process_matches(matches.start, ft_strlen(match_str), ln);
		LST_DEL(&matches);
	}
	ft_strdel(&match_str);
	return (res);
}
