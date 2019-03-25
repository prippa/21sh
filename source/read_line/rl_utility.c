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

void			rl_determine_x(t_line *ln, size_t n, uint16_t col)
{
	if (!n)
		return ;
	ln->x = (ln->x + n) % col;
	if (ln->x == 0)
		rl_make_tc_magic(tc()->down);
}

void			rl_clear_line(void)
{
	t_read_line	*r;
	t_tc		*t;

	r = rl();
	t = tc();
	if (r->w_size.ws_col)
		rl_move_cursor_up((r->prompt_size + r->ln.l_cur_pos)
			/ r->w_size.ws_col);
	rl_make_tc_magic(t->cr);
	rl_make_tc_magic(t->cd);
}

void			rl_redraw_line(t_line *ln, uint16_t col)
{
	ln->x = 0;
	ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	ft_putstr_fd(ln->line + ln->l_start, STDIN_FILENO);
	rl_determine_x(ln, (rl()->prompt_size + (ln->l_end - ln->l_start)), col);
	rl_move_cursor_left(ln, ln->l_end, ln->l_end - ln->l_cur_pos, col);
}
