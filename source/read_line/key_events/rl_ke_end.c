/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:35:20 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:35:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_end(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc,
			ln->l_end - ln->pc, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}
