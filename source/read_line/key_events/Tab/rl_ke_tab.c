/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:50:16 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 23:46:32 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_characters.h"
#include "auto_completion.h"
#include "environ_manipulation.h"
#include "info.h"

int32_t			rl_ke_tab(t_line *ln)
{
	int32_t	res;

	LST_INIT(&ac()->matches, &rl_t_del_match_list);
	res = ERR;
	if (rl_t_get_cmd_input_word(ln))
		rl_t_get_cmd_matches();
	if (!ac()->matches.start)
	{
		ft_strdel(&ac()->input_word);
		if (rl_t_get_path_input_word(ln))
			rl_t_get_path_matches();
	}
	if (ac()->matches.start)
	{
		res = tab_process_matches(ln);
		LST_DEL(&ac()->matches);
	}
	ft_strdel(&ac()->input_word);
	return (res);
}
