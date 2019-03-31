/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:24:06 by prippa            #+#    #+#             */
/*   Updated: 2019/03/25 14:24:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_search.h"

void		rl_history_add(const char *line)
{
	char		*l;
	char		*chr;
	t_list2		*new_obj;

	if (ft_is_str_space(line) || ft_is_str_empty(line) ||
		(rl()->hs.h_end && ft_strequ((char *)rl()->hs.h_end->content, line)))
		return ;
	if ((chr = ft_strchr(line, '\n')))
	{
		GET_MEM(MALLOC_ERR, l, ft_strsub, line, 0, chr - line);
	}
	else
	{
		GET_MEM(MALLOC_ERR, l, ft_strdup, line);
	}
	GET_MEM(MALLOC_ERR, new_obj, ft_lst2new, (void *)l, 0);
	ft_lst2_push_back(&rl()->hs.h_start, &rl()->hs.h_end, new_obj);
}

void		rl_history_move(const char *line, t_line *ln)
{
	rl_ke_ctrl_g(ln);
	rl_add_to_line(ln, line, rl()->w.ws_col, true);
}
