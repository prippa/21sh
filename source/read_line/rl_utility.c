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
#include <term.h>

#define GP_BUF_SIZE 30

static void	rl_ke_get_pos_calc(char buf[GP_BUF_SIZE], int32_t i, t_point *p)
{
	int32_t	_pow;

	--i;
	_pow = 1;
	while (buf[--i] != ';')
	{
		p->x = p->x + (buf[i] - '0') * _pow;
		_pow *= 10;
	}
	_pow = 1;
	while (buf[--i] != '[')
	{
		p->y = p->y + (buf[i] - '0') * _pow;
		_pow *= 10;
	}
}

t_point		rl_get_pos(void)
{
	char	buf[GP_BUF_SIZE + 1];
	char	ch;
	int32_t	i;
	t_point	p;

	ft_bzero(buf, GP_BUF_SIZE + 1);
	ft_bzero(&p, sizeof(t_point));
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
	rl_ke_get_pos_calc(buf, i, &p);
	--p.x;
	--p.y;
	return (p);
}

void		rl_goto(t_point p)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), p.x, p.y), STDIN_FILENO);
}

void		rl_do_magic(size_t len)
{
	char	*boom;

	GET_MEM(MALLOC_ERR, boom, ft_memalloc, len + 1);
	ft_memset(boom, ' ', len);
	ft_putstr_fd(boom, STDIN_FILENO);
}
