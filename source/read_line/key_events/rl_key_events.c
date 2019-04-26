/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:13:04 by prippa            #+#    #+#             */
/*   Updated: 2019/03/18 13:13:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"

static int32_t	rl_call_event(t_ke_event f, uint64_t key, t_line *ln)
{
	int32_t	res;
	t_line	tmp;

	ft_bzero(&tmp, sizeof(t_line));
	rl_line_cpy(&tmp, &rl()->prev_ln);
	if (key != KEY_CTRL_H)
		rl_line_cpy(&rl()->prev_ln, ln);
	res = f(ln);
	if (res == ERR)
		rl_line_cpy(&rl()->prev_ln, &tmp);
	rl_line_del(&tmp);
	return (res);
}

int32_t			rl_key_events(t_line *ln, const char buf[RL_BUFF_SIZE])
{
	uint64_t	key;
	t_ht_elem	*elem;

	ft_memcpy(&key, buf, RL_BUFF_SIZE);
	if ((elem = HT_GET(&rl()->button_keys, &key, sizeof(uint64_t))))
		return (rl_call_event(elem->value, key, ln));
	return (ERR);
}
