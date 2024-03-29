/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:11:40 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 17:11:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_search.h"

int32_t	rl_ke_ctrl_r(t_line *ln)
{
	rl_clear_line(ln, rl()->w.ws_col);
	ft_strcpy(hs()->reset_prompt, rl()->prompt);
	hs()->reset_prompt_size = rl()->prompt_size;
	hs()->reset_mod = rl()->mod;
	ft_strcpy(rl()->prompt, SEARCH_PROMPT);
	rl()->prompt_size = ft_strlen(SEARCH_PROMPT);
	rl_redraw_line(ln, rl()->w.ws_col);
	rl()->mod = M_SEARCH;
	return (OK);
}
