/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:41:06 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:41:09 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_return(t_line *ln)
{
	int32_t	ls_res;

	ft_putstr_fd("\n", STDIN_FILENO);
	if (!(ls_res = rl_line_syntax(ln)))
		return (RL_BREAK);
	ls_print_info(ls_res);
	if (ls_res < 0)
		return (RL_BREAK);
	if (rl()->new_line_flag)
		rl_add_to_line(ln, "\n", rl()->w_size.ws_col, false);
	if (ls_res > 0)
	{
		ln->l_end = 0;
		rl()->if_inhibitors_in_use_flag = true;
	}
	return (OK);
}
