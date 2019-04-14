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

int32_t	ls_rap_word(t_line_syntax *ls, t_line *ln)
{
	while (ln->line[ls->i])
	{
		if (ft_isalnum_in_case(ln->line[ls->i]) ||
			ln->line[ls->i] == SINGLE_QUOTES_C ||
			ln->line[ls->i] == DOUBLE_QUOTES_C ||
			ln->line[ls->i] == BACKSLASH_C ||
			ln->line[ls->i] == OFF_C)
			return (LS_OK);
		if (!ft_isspace(ln->line[ls->i]))
		{
			rl_ls_syntax_err_wtf_token((char[2]){ln->line[ls->i], 0});
			return (LS_SYNTAX_ERR);
		}
		++ls->i;
	}
	return (LS_NEW_PROMPT);
}

int32_t	ls_rap_pipe(t_line_syntax *ls, t_line *ln)
{
	int32_t	res;

	++ls->i;
	if (!ls->semi_flag)
	{
		rl_ls_syntax_err_wtf_token((char[2]){PIPE_C, 0});
		return (LS_SYNTAX_ERR);
	}
	if ((res = ls_rap_word(ls, ln)) == LS_NEW_PROMPT)
	{
		rl_ls_new_prompt(ln, false, LS_PIPE);
		return (LS_NEW_PROMPT);
	}
	return (res);
}

int32_t	ls_rap_redir_in(t_line_syntax *ls, t_line *ln)
{
	int32_t	res;

	++ls->i;
	if (ln->line[ls->i] == REDIRECT_IN_C || ln->line[ls->i] == FDA_C)
		++ls->i;
	if ((res = ls_rap_word(ls, ln)) == LS_NEW_PROMPT)
	{
		rl_ls_syntax_err_wtf_token("newline");
		return (LS_SYNTAX_ERR);
	}
	return (res);
}

int32_t	ls_rap_redir_out(t_line_syntax *ls, t_line *ln)
{
	int32_t	res;

	++ls->i;
	if (ln->line[ls->i] == REDIRECT_OUT_C || ln->line[ls->i] == FDA_C)
		++ls->i;
	if ((res = ls_rap_word(ls, ln)) == LS_NEW_PROMPT)
	{
		rl_ls_syntax_err_wtf_token("newline");
		return (LS_SYNTAX_ERR);
	}
	return (res);
}
