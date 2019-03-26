/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:34:58 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:35:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t			rl_ke_ctrl_left(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		ln->pc = rl_move_cursor_left(ln, ln->pc,
			ft_get_left_word(ln->line, ln->pc, ln->l_start),
			rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}
