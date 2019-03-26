/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:35:13 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:35:15 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_ctrl_up(t_line *ln)
{
	uint16_t	col;

	if (ln->pc > ln->l_start)
	{
		col = rl()->w.ws_col;
		ln->pc = rl_move_cursor_left(ln, ln->pc, col, col);
		return (OK);
	}
	return (ERR);
}
