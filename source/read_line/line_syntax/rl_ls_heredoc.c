/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:07:48 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:07:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

t_heredoc		*hd(void)
{
	static t_heredoc hd;

	return (&hd);
}

t_lexer_status	hd_init(t_line_syntax *ls, t_line *ln)
{
	hd()->heredoc_delimiter = sh_get_word(&ls->i, ln->line);
	hd()->end = ln->l_end + 1;
	hd()->start = ln->l_start;
	rl_ls_new_prompt(ln, true, LS_HEREDOC);
	rl()->mod = M_HEREDOC;
	return (LS_NEW_PROMPT);
}

void			hd_close(t_line *ln)
{
	char	*doc;

	ln->pc = ln->l_start;
	rl_del_from_line(ln, ln->l_end, rl()->w.ws_col, false);
	doc = ft_strdup(&ln->line[hd()->end]);
	ln->pc = hd()->end - 1;
	rl_del_from_line(ln, ln->l_end, rl()->w.ws_col, false);
	ln->l_start = hd()->start;
	LST_PUSH_BACK_REF(&hd()->heredoc, doc, ft_strlen(doc));
	ft_strdel(&hd()->heredoc_delimiter);
	rl()->mod = M_SYNTAX_2;
}

t_bool			hd_continue(t_line *ln)
{
	if (ft_strequ(&ln->line[ln->l_start], hd()->heredoc_delimiter))
	{
		hd_close(ln);
		return (false);
	}
	else
	{
		rl_ls_new_prompt(ln, true, LS_HEREDOC);
		return (true);
	}
}
