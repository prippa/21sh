/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:57:49 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:57:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"
#include "info.h"
#include "syntax_characters.h"
#include "builtin.h"
#include "button_keys.h"

t_lexer_status	ls_backslash_check(t_line_syntax *ls, t_line *ln)
{
	ls->semi_flag = true;
	if (!ln->line[++ls->i])
	{
		--ln->pc;
		rl_del_from_line(ln, ln->pc + 1,
			rl()->w.ws_col, false);
		rl_ls_new_prompt(ln, false, LS_SLASH);
		return (LS_NEW_PROMPT);
	}
	return (LS_OK);
}

t_lexer_status	ls_double_q_check(t_line_syntax *ls, t_line *ln)
{
	t_bool new_line_f;

	new_line_f = true;
	while (true)
	{
		if (!ln->line[++ls->i] ||
			(ln->line[ls->i] == BACKSLASH_C && !ln->line[ls->i + 1]))
		{
			if (ln->line[ls->i] == BACKSLASH_C && !ln->line[ls->i + 1])
			{
				--ln->pc;
				rl_del_from_line(ln, ln->pc + 1,
					rl()->w.ws_col, false);
				new_line_f = false;
			}
			rl_ls_new_prompt(ln, new_line_f, LS_DQ);
			return (LS_NEW_PROMPT);
		}
		if (ln->line[ls->i] == BACKSLASH_C)
			++ls->i;
		else if (ln->line[ls->i] == DOUBLE_QUOTES_C)
			return (LS_OK);
	}
}

t_lexer_status	ls_single_q_check(t_line_syntax *ls, t_line *ln)
{
	while (true)
	{
		if (!ln->line[++ls->i])
		{
			rl_ls_new_prompt(ln, true, LS_Q);
			return (LS_NEW_PROMPT);
		}
		if (ln->line[ls->i] == SINGLE_QUOTES_C)
			return (LS_OK);
	}
}

t_lexer_status	ls_semi_check(t_line_syntax *ls, t_line *ln)
{
	if (!ls->semi_flag)
	{
		if (ln->line[ls->i + 1] == SEMICOLON_C || (ls->i &&
			ln->line[ls->i - 1] == SEMICOLON_C))
			rl_ls_syntax_err_wtf_token((char[3]){SEMICOLON_C, SEMICOLON_C, 0});
		else
			rl_ls_syntax_err_wtf_token((char[2]){SEMICOLON_C, 0});
		return (LS_SYNTAX_ERR);
	}
	ls->semi_flag = false;
	return (LS_OK);
}
