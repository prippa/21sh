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

#include "button_keys.h"

int32_t		rl_ke_left(t_line *ln)
{
	if (ln->l_cur_pos > ln->l_start)
	{
		ln->l_cur_pos = rl_move_cursor_left(ln, ln->l_cur_pos,
			1, rl()->w_size.ws_col);
		return (OK);
	}
	return (ERR);
}
