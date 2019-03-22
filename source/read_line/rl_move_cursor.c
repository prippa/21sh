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

static void		rl_move_cursor_right(size_t n)
{
	t_tc	*t;

	t = tc();
	while (n--)
		rl_make_tc_magic(t->nd);
}

static void		rl_move_cursor_left(size_t n)
{
	t_tc	*t;

	t = tc();
	while (n--)
		rl_make_tc_magic(t->le);
}
//t_line *ln, t_motion_vector mv, size_t len
t_bool			rl_move_cursor(void)
{
	t_bool			op_res;
	t_tc	*t;

	t = tc();
	// system("clear");
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->up);
	sleep(1);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->up);
	sleep(1);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->up);
	sleep(1);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->up);
	sleep(1);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	sleep(1);
	rl_make_tc_magic(t->le);
	rl_make_tc_magic(t->up);
	rl_make_tc_magic(t->up);
	sleep(1);
	rl_make_tc_magic(t->nd);
	sleep(1);
	rl_make_tc_magic(t->down);
	sleep(1);
	// sleep(2);
	#include "builtin.h"
	sh_exit(NULL);
	op_res = false;
	return (op_res);
}
