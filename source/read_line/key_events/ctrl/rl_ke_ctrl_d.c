/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:34:13 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:34:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"
#include "line_syntax.h"
#include "builtin.h"

int32_t		rl_ke_ctrl_d(t_line *ln)
{
	if (ft_is_str_empty(ln->line))
		sh_exit(NULL);
	else if (rl()->inhibitors_in_use && ln->l_start == ln->l_end)
	{
		rl_ls_syntax_err(LS_WTF_EOF);
		return (RL_BREAK);
	}
	return (ERR);
}
