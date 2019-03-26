/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:33:07 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:33:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_right(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc, 1, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}
