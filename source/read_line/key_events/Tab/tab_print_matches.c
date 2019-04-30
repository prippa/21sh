/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_print_matches.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:39:04 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 18:43:48 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"
#include <math.h>

#define SEPARATOR_SIZE 1

static t_bool	rl_t_sort_matches(const void *left_cnt, const void *right_cnt)
{
	if (ft_strcmp(((t_match *)left_cnt)->name,
		((t_match *)right_cnt)->name) > 0)
		return (true);
	return (false);
}

static void		rl_t_print_matches_logic(const t_list_elem *start,
					uint16_t col, size_t width)
{
	size_t		n;
	t_match		*m;

	n = 0;
	width += SEPARATOR_SIZE;
	while (start)
	{
		if ((n + width) >= col)
		{
			rl_make_tc_magic(tc()->down);
			n = 0;
		}
		m = (t_match *)start->content;
		ft_dprintf(STDIN_FILENO, "%~-*s",
			m->color_type, m->color, width, m->name);
		start = start->next;
		n += width;
	}
	rl_make_tc_magic(tc()->down);
}

void			rl_t_print_matches(t_line *ln, size_t width)
{
	t_line		buf_ln;

	ft_memcpy(&buf_ln, ln, sizeof(t_line));
	rl_ke_end(&buf_ln);
	if (buf_ln.x)
		rl_make_tc_magic(tc()->down);
	ft_lstsort(&ac()->matches, &rl_t_sort_matches);
	rl_t_print_matches_logic(ac()->matches.start, rl()->w.ws_col, width);
	rl_redraw_line(ln, rl()->w.ws_col);
}
