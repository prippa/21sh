/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_basic_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:54:27 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:54:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t	rl_ke_back_space(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		rl_ke_left(ln);
		rl_del_from_line(ln, ln->pc + 1, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_delete(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		rl_del_from_line(ln, ln->pc + 1, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_return(t_line *ln)
{
	rl_ke_end(ln);
	if (ln->x)
		rl_make_tc_magic(tc()->down);
	if (rl_line_syntax(ln))
	{
		rl_history_add(ln->line);
		return (RL_BREAK);
	}
	return (OK);
}

int32_t	rl_ke_home(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		ln->pc = rl_move_cursor_left(ln, ln->pc, ln->pc, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_end(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc,
			ln->l_end - ln->pc, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}
