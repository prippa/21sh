/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_g_u_k.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:54:34 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:54:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t	rl_ke_ctrl_g(t_line *ln)
{
	if (!ft_is_str_empty(ln->line))
	{
		rl_ke_home(ln);
		rl_del_from_line(ln, ln->l_end, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_ctrl_u(t_line *ln)
{
	size_t end;

	if (ln->pc > ln->l_start)
	{
		end = ln->pc;
		rl_ke_home(ln);
		rl_del_from_line(ln, end, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}

int32_t	rl_ke_ctrl_k(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		rl_del_from_line(ln, ln->l_end, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}
