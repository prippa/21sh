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

#include "button_keys.h"

static t_event const	g_ke[KE_SIZE] =
{
	{rl_ke_left, KEY_LEFT},
	{rl_ke_right, KEY_RIGHT},
	{rl_ke_up, KEY_UP},
	{rl_ke_down, KEY_DOWN},
	{rl_ke_return, KEY_RETURN},
	{rl_ke_back_space, KEY_BACK_SPACE},
	{rl_ke_delete, KEY_DELETE},
	{rl_ke_ctrl_d, KEY_CTRL_D},
	{rl_ke_ctrl_a, KEY_CTRL_A},
	{rl_ke_alt_left, KEY_ALT_LEFT},
	{rl_ke_alt_right, KEY_ALT_RIGHT},
	{rl_ke_alt_up, KEY_ALT_UP},
	{rl_ke_alt_down, KEY_ALT_DOWN},
	{rl_ke_tab, KEY_TAB},
	{rl_ke_home, KEY_HOME},
	{rl_ke_end, KEY_END},
};

int32_t					rl_key_events(const char buf[RL_BUFF_SIZE])
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
		if (g_ke[i].key == key)
			return (g_ke[i].f(&rl()->ln));
	return (OK);
}
