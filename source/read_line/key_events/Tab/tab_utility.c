/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:20:32 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 23:17:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"

t_ac			*ac(void)
{
	static t_ac		ac;

	return (&ac);
}

void		rl_t_push_match(const char *f, size_t f_len,
				int32_t f_color, int32_t f_color_type)
{
	char	*cmd;
	size_t	iw_len;

	iw_len = ft_strlen(ac()->input_word);
	if (iw_len <= f_len && ft_strnequ(ac()->input_word, f, iw_len))
	{
		cmd = ft_strsub(f, 0, f_len);
		LST_PUSH_BACK(&ac()->matches,
			(MATCH(cmd, f_color, f_color_type)), sizeof(t_match));
	}
}

void		rl_t_del_match_list(void *content, size_t content_size)
{
	t_match		*m;

	(void)content_size;
	m = (t_match *)content;
	ft_strdel(&m->name);
	ft_memdel(&content);
}
