/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:33:25 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:33:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t		rl_ke_down(t_line *ln)
{
	t_read_line *r;

	r = rl();
	if (r->hs.curent)
	{
		if (!r->hs.curent->next)
			rl_history_move(r->hs.cur_line_buf, ln);
		else
			rl_history_move((char *)r->hs.curent->next->content, ln);
		r->hs.curent = r->hs.curent->next;
		return (OK);
	}
	return (ERR);
}
