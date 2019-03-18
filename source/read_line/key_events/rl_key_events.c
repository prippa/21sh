/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:13:04 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:13:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "keys.h"

int32_t		rl_key_events(char buf[RL_BUFF_SIZE])
{
	if ((UP) || (DOWN) || (LEFT) || (RIGHT) || (WTF_UP) || (WTF_DOWN) ||
	(BACK_SPACE) || (TAB) || (CTRL_D) || (NEW_LINE))
	{
		if (BACK_SPACE)
			rl_ke_back_space();
		else if (TAB)
			rl_ke_tab();
		else if (CTRL_D)
			rl_ke_ctrl_d();
		else if (NEW_LINE)
			return (rl_ke_return());
		return (RL_CONTINUE);
	}
	return (RL_OK);
}
