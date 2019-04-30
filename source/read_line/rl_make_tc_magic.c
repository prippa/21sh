/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_make_tc_magic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:54:17 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 17:42:36 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

static int32_t	rl_print_key(int32_t n)
{
	return ((int32_t)write(STDIN_FILENO, &n, 1));
}

void			rl_make_tc_magic(const char *t)
{
	tputs(t, 0, &rl_print_key);
}

void			rl_goto_x(uint16_t x)
{
	tputs(tgoto(tc()->ch, 0, x), 0, &rl_print_key);
}
