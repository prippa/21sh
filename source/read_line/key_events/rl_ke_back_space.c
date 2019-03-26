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

#include "button_keys.h"

int32_t		rl_ke_back_space(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		rl_ke_left(ln);
		rl_del_from_line(ln, ln->pc + 1, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}
