/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:01:14 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 19:01:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

void			rl_move_x(int32_t *x, size_t n, uint16_t col)
{
	if (!n)
		return ;
	*x = (*x + n) % col;
	if (*x == 0)
		rl_make_tc_magic(tc()->down);
}

void			rl_clear_line(t_line *ln, uint16_t col)
{
	t_tc	*t;
	size_t	n;

	t = tc();
	n = 0;
	if (col)
		n = (rl()->prompt_size + (ln->pc - ln->l_start)) / col;
	while (n--)
		rl_make_tc_magic(t->up);
	rl_make_tc_magic(tc()->cr);
	rl_make_tc_magic(tc()->cd);
}

void			rl_redraw_line(t_line *ln, uint16_t col)
{
	ft_putstr_fd(rl()->prompt, STDIN_FILENO);
	ft_putstr_fd(ln->line + ln->l_start, STDIN_FILENO);
	ln->x = 0;
	rl_move_x(&ln->x, (rl()->prompt_size + (ln->l_end - ln->l_start)), col);
	rl_move_cursor_left(ln, ln->l_end, ln->l_end - ln->pc, col);
}
