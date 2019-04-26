/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_arrows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:54:48 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:54:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t	rl_ke_ctrl_left(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		ln->pc = rl_move_cursor_left(ln, ln->pc,
			ft_get_left_word(ln->line, ln->pc, ln->l_start),
			rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_ctrl_right(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc,
			ft_get_right_word(ln->line, ln->pc, ln->l_end),
			rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_ctrl_up(t_line *ln)
{
	uint16_t	col;

	if (ln->pc > ln->l_start)
	{
		col = rl()->w.ws_col;
		ln->pc = rl_move_cursor_left(ln, ln->pc, col, col);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_ctrl_down(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc,
			rl()->w.ws_col, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}
