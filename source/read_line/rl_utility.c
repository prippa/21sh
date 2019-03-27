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

void	rl_determine_x(t_line *ln, size_t n, uint16_t col)
{
	if (!n)
		return ;
	ln->x = (ln->x + n) % col;
	if (ln->x == 0)
		rl_make_tc_magic(tc()->down);
}

int32_t	rl_get_x_pos(const char *u7_str)
{
	char	buf[30];
	char	ch;
	size_t	i;

	i = -1;
	write(STDOUT_FILENO, u7_str, 4);
	read(STDOUT_FILENO, buf, 30);
	// while (ch != 'R')
	// {
	// 	if (!read(STDIN_FILENO, &ch, 1))
	// 		sh_fatal_err(READ_ERR);
	// 	buf[++i] = ch;
	// }
	i = 0;
	while (buf[i] != ';')
		++i;
	return (ft_atoi(&buf[i + 1]));
}

void	rl_clear_line(t_line *ln, uint16_t col)
{
	if (col)
		rl_move_cursor_up((rl()->prompt_size + ln->pc) / col);
	rl_make_tc_magic(tc()->cr);
	rl_make_tc_magic(tc()->cd);
}

void	rl_redraw_line(t_line *ln, uint16_t col)
{
	ln->x = 0;
	ft_putstr_fd(rl()->prompt, STDIN_FILENO);
	ft_putstr_fd(ln->line + ln->l_start, STDIN_FILENO);
	rl_determine_x(ln, (rl()->prompt_size + (ln->l_end - ln->l_start)), col);
	rl_move_cursor_left(ln, ln->l_end, ln->l_end - ln->pc, col);
}
