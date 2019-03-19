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

#include "keys.h"

static const int64_t g_keys[KE_SIZE] =
	{
		KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,
		KEY_RETURN,
		KEY_BACK_SPACE, KEY_DELETE,
		KEY_CTRL_D, KEY_CTRL_A,
		KEY_ALT_LEFT, KEY_ALT_RIGHT, KEY_ALT_UP, KEY_ALT_DOWN,
		KEY_TAB,
		KEY_HOME, KEY_END};

typedef int32_t (*t_events)(t_line *ln);
static const t_events g_ke[KE_SIZE] =
	{
		rl_ke_left, rl_ke_right, rl_ke_up, rl_ke_down,
		rl_ke_return,
		rl_ke_back_space, rl_ke_delete,
		rl_ke_ctrl_d, rl_ke_ctrl_a,
		rl_ke_alt_left, rl_ke_alt_right, rl_ke_alt_up, rl_ke_alt_down,
		rl_ke_tab,
		rl_ke_home, rl_ke_end};

int32_t rl_key_events(const char buf[RL_BUFF_SIZE])
{
	uint64_t key;
	size_t i;

	ft_memcpy(&key, buf, RL_BUFF_SIZE);
	// uint32_t y = 0, x = 0;
	// rl_get_pos(&y, &x);
	// ft_printf("\ny - [%d] x - [%d]\n", y, x);
	// #include "builtin.h"
	// sh_exit(NULL);
	i = -1;
	while (++i < KE_SIZE)
		if (g_keys[i] == key)
			return (g_ke[i](&rl()->ln));
	return (OK);
}
