/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:10:33 by prippa            #+#    #+#             */
/*   Updated: 2019/03/20 11:10:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

size_t			rl_move_cursor_right(t_line *ln, size_t pc,
					size_t n, uint16_t col)
{
	t_tc	*t;

	t = tc();
	while (n-- && pc < ln->l_end)
	{
		if (ln->x == col - 1)
		{
			rl_make_tc_magic(t->down);
			ln->x = 0;
		}
		else
			++ln->x;
		++pc;
	}
	rl_goto_x(ln->x);
	return (pc);
}

size_t			rl_move_cursor_left(t_line *ln, size_t pc,
					size_t n, uint16_t col)
{
	t_tc	*t;

	t = tc();
	while (n-- && pc > ln->l_start)
	{
		if (ln->x == 0)
		{
			rl_make_tc_magic(t->up);
			ln->x = col - 1;
		}
		else
			--ln->x;
		--pc;
	}
	rl_goto_x(ln->x);
	return (pc);
}
