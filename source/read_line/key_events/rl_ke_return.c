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
	rl_ke_end(ln);
	if (ln->x)
		ft_putstr_fd("\n", STDIN_FILENO);
	if (rl_line_syntax(ln))
	{
		rl_history_add(ln->line);
		return (RL_BREAK);
	}
	return (OK);
}
