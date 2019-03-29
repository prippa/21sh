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

// static int32_t	rl_get_x_pos(void)
// {
// 	char	buf[30];
// 	size_t	i;

// 	ft_bzero(buf, 30);
// 	write(STDOUT_FILENO, tc()->u7, 4);
// 	if (read(STDOUT_FILENO, buf, 100) == ERR)
// 		ft_fatal_err_exit(READ_ERR);
// 	i = 0;
// 	while (buf[i] != ';')
// 		++i;
// 	return (ft_atoi(&buf[i + 1]));
// }

// void			rl_determine_x(t_line *ln, uint16_t col)
// {
// 	ln->x = rl_get_x_pos() - 1;
// 	if (ln->x == col)
// 	{
// 		ln->x = 0;
// 		rl_make_tc_magic(tc()->down);
// 	}
// }

static void		rl_determine_x(int32_t *x, const char *line, uint16_t col)
{
	if (!line || !*line)
		return ;
	while (*line)
	{
		if (*x == col - 1 || *line == '\n')
			*x = 0;
		else
			*x += 1;
		++line;
	}
	if (*x == 0)
		rl_make_tc_magic(tc()->down);
}

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
	if (col)
		rl_move_cursor_up((rl()->prompt_size + ln->pc) / col);
	rl_make_tc_magic(tc()->cr);
	rl_make_tc_magic(tc()->cd);
}

void			rl_redraw_line(t_line *ln, uint16_t col)
{
	ln->x = 0;
	ft_putstr_fd(rl()->prompt, STDIN_FILENO);
	rl_move_x(&ln->x, rl()->prompt_size, col);
	ft_putstr_fd(ln->line + ln->l_start, STDIN_FILENO);
	rl_determine_x(&ln->x, ln->line + ln->l_start, col);
	rl_move_cursor_left(ln, ln->l_end, ln->l_end - ln->pc, col);
}
