/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_back_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:39:49 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:39:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

int32_t		rl_ke_back_space(t_line *ln)
{
	return (OK);
}

// void		rl_ke_back_space(void)
// {
// 	if (rl()->len)
// 	{
// 		--rl()->len;
// 		GET_MEM(MALLOC_ERR, rl()->line, ft_strsub_free,
// 			&rl()->line, 0, ft_strlen(rl()->line) - 1);
// 		ft_putstr("\b  \b\b");
// 	}
// }
