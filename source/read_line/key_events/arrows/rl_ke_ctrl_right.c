/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:35:06 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:35:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_ctrl_right(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc,
			ft_get_right_word(ln->line, ln->pc, ln->l_end),
			rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}
