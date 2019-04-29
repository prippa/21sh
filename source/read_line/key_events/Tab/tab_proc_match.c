/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_proc_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:50:22 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 00:15:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"
#include "info.h"

static size_t	rl_t_get_max_len(const t_list_elem *start)
{
	size_t	max;
	size_t	wtf;

	max = ft_strlen(((t_match *)start->content)->name);
	while (start->next)
	{
		wtf = ft_strlen(((t_match *)start->next->content)->name);
		if (wtf > max)
			max = wtf;
		start = start->next;
	}
	return (max);
}

static t_bool	rl_t_compare(const char *cmpr_str,
					const t_list_elem *iter, size_t len)
{
	while (iter)
	{
		if (!ft_strnequ(cmpr_str, ((t_match *)iter->content)->name, len))
			return (true);
		iter = iter->next;
	}
	return (false);
}

static void		rl_t_draw_matches(const t_list_elem *start, size_t col, size_t max)
{
	size_t	n;
	t_match	*m;

	n = 0;
	while (start)
	{
		if ((n + max + 2) >= col)
		{
			rl_make_tc_magic(tc()->down);
			n = 0;
		}
		m = (t_match *)start->content;
		ft_dprintf(STDIN_FILENO, "%~-*s  ",
			m->color_type, m->color, max, m->name);
		start = start->next;
		n += max + 2;
	}
	rl_make_tc_magic(tc()->down);
}

static int32_t	rl_t_end_move(const char *postfix, const t_list_elem *start,
					t_line *ln, size_t max)
{
	t_line		buf_ln;

	ft_memcpy(&buf_ln, ln, sizeof(t_line));
	if (*postfix)
	{
		rl_add_to_line(ln, postfix, rl()->w.ws_col, true);
		return (OK);
	}
	rl_ke_end(&buf_ln);
	if (buf_ln.x)
		rl_make_tc_magic(tc()->down);
	rl_t_draw_matches(start, rl()->w.ws_col, max);
	rl_redraw_line(ln, rl()->w.ws_col);
	return (ERR);
}

int32_t			tab_process_matches(t_line *ln)
{
	char	postfix[FILENAME_MAX + 1];
	size_t	elem_max_len;
	size_t	len;
	t_match	*m;

	ft_bzero(postfix, FILENAME_MAX + 1);
	elem_max_len = rl_t_get_max_len(ac()->matches.start);
	len = ft_strlen(ac()->input_word);
	while (true)
	{
		if (++len > elem_max_len)
		{
			if (ln->pc == ln->l_end &&
				postfix[ft_strlen(postfix) - 1] != UNIX_PATH_SEPARATOR)
				ft_strcat(postfix, " ");
			break ;
		}
		m = (t_match *)ac()->matches.start->content;
		if ((rl_t_compare(m->name, ac()->matches.start->next, len)))
			break ;
		else
			ft_strncat(postfix, &m->name[len - 1], 1);
	}
	return (rl_t_end_move(postfix, ac()->matches.start, ln, elem_max_len));
}
