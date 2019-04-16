/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_rap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:40:18 by prippa            #+#    #+#             */
/*   Updated: 2019/04/13 13:40:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"
#include "syntax_characters.h"

t_lexer_status			ls_rap_pipe(t_line_syntax *ls, t_line *ln)
{
	t_lexer_status	res;

	++ls->i;
	if (!ls->semi_flag)
	{
		rl_ls_syntax_err_wtf_token((char[2]){PIPE_C, 0});
		return (LS_SYNTAX_ERR);
	}
	res = ls_check_word(ls, ln);
	if (res == LS_NEW_PROMPT)
		rl_ls_new_prompt(ln, false, LS_PIPE);
	return (res);
}

static t_lexer_status	rl_ls_init_heredoc(t_line_syntax *ls, t_line *ln)
{
	rl()->heredoc_delimiter = ls_get_word(ls, ln);
	ft_printf("[%s]\n", rl()->heredoc_delimiter);
	return (0);
}

t_lexer_status			ls_rap_redir_in(t_line_syntax *ls, t_line *ln)
{
	t_lexer_status	status;
	t_bool			heredoc;

	heredoc = false;
	++ls->i;
	if (ln->line[ls->i] == REDIRECT_IN_C || ln->line[ls->i] == FDA_C)
	{
		if (ln->line[ls->i] == REDIRECT_IN_C)
			heredoc = true;
		++ls->i;
	}
	status = ls_check_word(ls, ln);
	if (status == LS_NEW_PROMPT)
		rl_ls_syntax_err_wtf_token("newline");
	if (heredoc && status == LS_OK)
		return (rl_ls_init_heredoc(ls, ln));
	return (status ? LS_SYNTAX_ERR : status);
}

t_lexer_status			ls_rap_redir_out(t_line_syntax *ls, t_line *ln)
{
	t_lexer_status status;

	++ls->i;
	if (ln->line[ls->i] == REDIRECT_OUT_C || ln->line[ls->i] == FDA_C)
		++ls->i;
	status = ls_check_word(ls, ln);
	if (status == LS_NEW_PROMPT)
		rl_ls_syntax_err_wtf_token("newline");
	return (status ? LS_SYNTAX_ERR : status);
}
