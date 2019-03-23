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

static int32_t	rl_print_key(int32_t n)
{
	return (write(STDIN_FILENO, &n, 1));
}

void			rl_make_tc_magic(const char *t)
{
	tputs(t, 0, &rl_print_key);
}

void			rl_determine_x(t_line *ln, size_t n, uint16_t col)
{
	if (!n)
		return ;
	ln->x = (ln->x + n) % col;
	if (ln->x == 0)
		rl_make_tc_magic(tc()->down);
}

void			rl_redraw_line(t_line *ln, uint16_t col)
{
	t_tc	*t;
	size_t	left_len;

	t = tc();
	ln->x = 0;
	left_len = ln->l_end - ln->l_cur_pos;
	ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	ft_putstr_fd(ln->line, STDIN_FILENO);
	rl_determine_x(ln, (P_SIZE + ln->l_end), col);
	ln->l_cur_pos = ln->l_end;
	rl_move_cursor_left(ln, left_len, col);
}

void			rl_goto_x(uint16_t x)
{
	tputs(tgoto(tc()->ch, 0, x), 0, rl_print_key);
}
