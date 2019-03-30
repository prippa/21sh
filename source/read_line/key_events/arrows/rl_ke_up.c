/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:33:16 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:33:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

int32_t			rl_ke_up(t_line *ln)
{
	t_read_line *r;

	r = rl();
	if (!r->hs.curent)
	{
		if (!r->hs.h_end)
			return (ERR);
		r->hs.curent = r->hs.h_end;
		GET_MEM(MALLOC_ERR, r->hs.cur_line_buf, ft_strdup_free,
			&r->hs.cur_line_buf, ln->line + ln->l_start);
		rl_history_move((char *)r->hs.curent->content, ln);
		return (OK);
	}
	else if (r->hs.h_start && r->hs.curent != r->hs.h_start)
	{
		r->hs.curent = r->hs.curent->prev;
		rl_history_move((char *)r->hs.curent->content, ln);
		return (OK);
	}
	return (ERR);
}
