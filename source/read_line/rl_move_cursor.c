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
#include <sys/ioctl.h>

static t_bool	rl_mv_right(t_line *ln, t_point *p,
					struct winsize w, size_t len)
{
	size_t	cur;

	cur = ln->cursor_pos;
	while (len--)
	{
		if (p->x == w.ws_col - 1)
		{
			p->x = -1;
			if (p->y == w.ws_row - 1)
				return (false);
			++p->y;
		}
		if (cur > ln->line_len)
			return (false);
		++cur;
		++p->x;
	}
	ln->cursor_pos = cur;
	return (true);
}

static t_bool	rl_mv_left(t_line *ln, t_point *p,
					struct winsize w, size_t len)
{
	size_t	cur;

	cur = ln->cursor_pos;
	while (len--)
	{
		if (p->x == 0)
		{
			p->x = w.ws_col;
			if (p->y == 0)
				return (false);
			--p->y;
		}
		if (cur == 0)
			return (false);
		--cur;
		--p->x;
	}
	ln->cursor_pos = cur;
	return (true);
}

t_bool			rl_move_cursor(t_line *ln, t_motion_vector mv, size_t len)
{
	struct winsize	w;
	t_point			p;
	t_bool			op_res;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	p = rl_get_pos();
	sleep(1);
	ft_printf("y = (%d) x = (%d)\n", p.y, p.x);
	ft_printf("colr - %d, row - %d\n", w.ws_col, w.ws_row);
	sleep(1);
	rl_goto((t_point){.x = 0, .y = 0});
	p = rl_get_pos();
	sleep(1);
	ft_printf("y = (%d) x = (%d)\n", p.y, p.x);
	p = rl_get_pos();
	rl_goto(p);
	sleep(1);
	p = rl_get_pos();
	rl_goto(p);
	sleep(1);
	p = rl_get_pos();
	rl_goto(p);
	sleep(1);
	p = rl_get_pos();
	rl_goto(p);
	sleep(1);
	#include "builtin.h"
	sh_exit(NULL);
	op_res = false;
	// if (mv == MV_LEFT)
	// 	op_res = rl_mv_left(ln, &p, w, len);
	// else if (mv == MV_RIGHT)
	// 	op_res = rl_mv_right(ln, &p, w, len);
	// if (op_res)
	// 	rl_goto(p);
	return (op_res);
}
