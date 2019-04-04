/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_arrows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
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
	if (!rl()->hs.curent)
	{
		if (!rl()->hs.history.end)
			return (ERR);
		rl()->hs.curent = rl()->hs.history.end;
		GET_MEM(MALLOC_ERR, rl()->hs.cur_line_buf, ft_strdup_free,
			&rl()->hs.cur_line_buf, ln->line + ln->l_start);
		rl_history_move((char *)rl()->hs.curent->content, ln);
		return (OK);
	}
	else if (rl()->hs.history.start &&
		rl()->hs.curent != rl()->hs.history.start)
	{
		rl()->hs.curent = rl()->hs.curent->prev;
		rl_history_move((char *)rl()->hs.curent->content, ln);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_down(t_line *ln)
{
	if (rl()->hs.curent)
	{
		if (!rl()->hs.curent->next)
			rl_history_move(rl()->hs.cur_line_buf, ln);
		else
			rl_history_move((char *)rl()->hs.curent->next->content, ln);
		rl()->hs.curent = rl()->hs.curent->next;
		return (OK);
	}
	return (ERR);
}
