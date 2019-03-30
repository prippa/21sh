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
	{&rl_ke_ctrl_a, KEY_CTRL_A},
	{&rl_ke_ctrl_e, KEY_CTRL_E},
	{&rl_ke_delete, KEY_DELETE},
	{&rl_ke_back_space, KEY_BACK_SPACE},
	{&rl_ke_home, KEY_HOME},
	{&rl_ke_end, KEY_END},
	{&rl_ke_left, KEY_LEFT},
	{&rl_ke_right, KEY_RIGHT},
	{&rl_ke_up, KEY_UP},
	{&rl_ke_down, KEY_DOWN},
	{&rl_ke_return, KEY_RETURN},
	{&rl_ke_ctrl_left, KEY_CTRL_LEFT},
	{&rl_ke_ctrl_right, KEY_CTRL_RIGHT},
	{&rl_ke_ctrl_up, KEY_CTRL_UP},
	{&rl_ke_ctrl_down, KEY_CTRL_DOWN},
	{&rl_ke_ctrl_shift_left, KEY_CTRL_SHIFT_LEFT},
	{&rl_ke_ctrl_shift_right, KEY_CTRL_SHIFT_RIGHT},
	{&rl_ke_ctrl_shift_up, KEY_CTRL_SHIFT_UP},
	{&rl_ke_ctrl_shift_down, KEY_CTRL_SHIFT_DOWN},
	{&rl_ke_ctrl_d, KEY_CTRL_D},
	{&rl_ke_ctrl_g, KEY_CTRL_G},
	{&rl_ke_ctrl_u, KEY_CTRL_U},
	{&rl_ke_ctrl_k, KEY_CTRL_K},
	{&rl_ke_ctrl_h, KEY_CTRL_H},
	{&rl_ke_ctrl_l, KEY_CTRL_L},
	{&rl_ke_tab, KEY_TAB},
};

static int32_t			rl_call_event(t_func f, uint64_t key, t_line *ln)
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

int32_t					rl_key_events(t_line *ln, const char buf[RL_BUFF_SIZE])
{
	uint64_t	key;
	size_t		i;

	ft_memcpy(&key, buf, RL_BUFF_SIZE);
	if (key = KEY_CTRL_R)
		key = rl_ke_ctrl_r(ln);
	i = -1;
	while (++i < KE_SIZE)
		if (g_ke[i].key == key)
			return (rl_call_event(g_ke[i].f, key, ln));
	return (ERR);
}
