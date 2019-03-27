/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:07 by prippa            #+#    #+#             */
/*   Updated: 2019/03/27 12:13:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_ctrl_h(t_line *ln)
{
	t_line		tmp;

	ft_bzero(&tmp, sizeof(t_line));
	rl_line_cpy(&tmp, ln);
	rl_line_cpy(ln, &rl()->prev_ln);
	rl_line_cpy(&rl()->prev_ln, &tmp);
	rl_clear_line(&tmp, rl()->w.ws_col);
	rl_redraw_line(ln, rl()->w.ws_col);
	rl_line_del(&tmp);
	return (OK);
}
