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

void			rl_increase_x(t_line *ln, size_t n, uint16_t col)
{
	ln->x = (ln->x + n) % col;
	if (ln->x == 0)
		rl_make_tc_magic(tc()->down);
}

void			rl_redraw_line(t_line *ln)
{
	ln->x = 0;
	ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	ft_putstr_fd(ln->line, STDIN_FILENO);
	rl_increase_x(ln, (P_SIZE + ln->line_len)
		- (ln->line_len - ln->cursor_pos), rl()->w_size.ws_col);
}
