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

void			rl_move_cursor_up(size_t n)
{
	t_tc	*t;

	t = tc();
	while (n--)
		rl_make_tc_magic(t->up);
}

void			rl_move_cursor_right(t_line *ln, size_t n, uint16_t col)
{
	t_tc	*t;
	size_t	i;

	t = tc();
	i = -1;
	while (++i < n && ln->l_cur_pos < ln->l_end)
	{
		if (ln->x == col - 1)
		{
			rl_make_tc_magic(t->down);
			ln->x = 0;
		}
		else
		{
			rl_make_tc_magic(t->nd);
			++ln->x;
		}
		++ln->l_cur_pos;
	}
}

void			rl_move_cursor_left(t_line *ln, size_t n, uint16_t col)
{
	t_tc	*t;
	size_t	i;

	t = tc();
	i = -1;
	while (++i < n && ln->l_cur_pos > ln->l_start)
	{
		if (ln->x == 0)
		{
			rl_make_tc_magic(t->up);
			rl_goto_x(col - 1);
			ln->x = col - 1;
		}
		else
		{
			rl_make_tc_magic(t->le);
			--ln->x;
		}
		--ln->l_cur_pos;
	}
}
