/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:46:29 by prippa            #+#    #+#             */
/*   Updated: 2019/04/04 20:46:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_search.h"

static void		rl_hs_new_mask_add(t_line *ln, const char *new_data)
{
	if (ft_strlen(new_data) + rl()->prompt_size > PROMPT_SIZE)
		return ;
	ft_strjoin_free(&hs()->search_str, new_data,
		ft_strlen(hs()->search_str), ft_strlen(new_data));
	rl_hs_new_mask(ln);
}

static void		rl_hs_new_mask_del(t_line *ln)
{
	if (!ft_is_str_empty(hs()->search_str))
	{
		ft_strsub_free(&hs()->search_str, 0, ft_strlen(hs()->search_str) - 1);
		rl_hs_new_mask(ln);
	}
}

static void		rl_hs_set_default_mod(t_line *ln)
{
	rl_clear_line(ln, rl()->w.ws_col);
	ft_strcpy(rl()->prompt, hs()->reset_prompt);
	rl()->prompt_size = hs()->reset_prompt_size;
	rl_redraw_line(ln, rl()->w.ws_col);
	ft_strdel(&hs()->search_str);
	rl()->mod = hs()->reset_mod;
}

static void		rl_hs_init(void)
{
	if (hs()->search_str)
		return ;
	hs()->search_str = ft_strdup(EMPTY_STR);
	hs()->h_current = rl()->hs.history.end;
}

t_bool			rl_history_search(t_line *ln, const char buf[RL_BUFF_SIZE])
{
	uint64_t key;

	ft_memcpy(&key, buf, RL_BUFF_SIZE);
	rl_hs_init();
	if (ft_is_str_print(buf))
		rl_hs_new_mask_add(ln, buf);
	else if (key == KEY_CTRL_R)
		rl_hs_continue_revers_search(ln);
	else if (key == KEY_BACKSPACE)
		rl_hs_new_mask_del(ln);
	else
	{
		rl_hs_set_default_mod(ln);
		return (false);
	}
	return (true);
}
