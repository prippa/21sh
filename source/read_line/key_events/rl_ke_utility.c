/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:01:14 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 19:01:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include <term.h>

#define GP_BUF_SIZE 30

void		rl_goto(int32_t x, int32_t y)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), STDIN_FILENO);
}

static void	rl_ke_get_pos_calc(char buf[GP_BUF_SIZE], int32_t i,
				int32_t *x, int32_t *y)
{
	int32_t	p;

	--i;
	p = 1;
	while (buf[--i] != ';')
	{
		*y = *y + (buf[i] - '0') * p;
		p *= 10;
	}
	p = 1;
	while (buf[--i] != '[')
	{
		*x = *x + (buf[i] - '0') * p;
		p *= 10;
	}
}

void		rl_get_pos(int32_t *x, int32_t *y)
{
	char	buf[GP_BUF_SIZE + 1];
	char	ch;
	int32_t	i;

	ft_bzero(buf, GP_BUF_SIZE + 1);
	write(1, "\033[6n", 4);
	i = 0;
	while (ch != 'R')
	{
		if (!read(STDIN_FILENO, &ch, 1))
			sh_fatal_err(READ_ERR);
		buf[i++] = ch;
	}
	if (i < 2)
		sh_fatal_err("rl_get_pos: i < 2");
	rl_ke_get_pos_calc(buf, i, y, x);
	*x -= 1;
	*y -= 1;
}
