/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:32:55 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:32:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

int32_t		rl_ke_left(t_line *ln)
{
	if (ln->cursor_pos)
		rl_move_cursor(ln, MV_LEFT, 1);
	return (OK);
}
