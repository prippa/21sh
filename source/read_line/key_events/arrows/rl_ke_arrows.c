/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_arrows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:54:54 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:54:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t	rl_ke_left(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		ln->pc = rl_move_cursor_left(ln, ln->pc, 1, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_right(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc, 1, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_up(t_line *ln)
{
	if (!rl()->hs.current)
	{
		if (!rl()->hs.history.end)
			return (ERR);
		rl()->hs.current = rl()->hs.history.end;
		ft_strdup_free(&rl()->hs.cur_line_buf, ln->line + ln->l_start);
		rl_history_move((char *)rl()->hs.current->content, ln);
		return (OK);
	}
	else if (rl()->hs.history.start &&
		rl()->hs.current != rl()->hs.history.start)
	{
		rl()->hs.current = rl()->hs.current->prev;
		rl_history_move((char *)rl()->hs.current->content, ln);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_down(t_line *ln)
{
	if (rl()->hs.current)
	{
		if (!rl()->hs.current->next)
			rl_history_move(rl()->hs.cur_line_buf, ln);
		else
			rl_history_move((char *)rl()->hs.current->next->content, ln);
		rl()->hs.current = rl()->hs.current->next;
		return (OK);
	}
	return (ERR);
}
