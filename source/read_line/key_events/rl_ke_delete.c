/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:40:45 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:40:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_delete(t_line *ln)
{
	if (ln->l_cur_pos < ln->l_end)
	{
		rl_del_from_line(ln, ln->l_cur_pos + 1, rl()->w_size.ws_col, true);
		return (OK);
	}
	return (ERR);
}
