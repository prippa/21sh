/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:34:13 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:34:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "builtin.h"

int32_t		rl_ke_ctrl_d(t_cursor *cur)
{
	(void)cur;
	if (ft_is_str_empty(rl()->line))
		sh_exit(NULL);
	return (OK);
}