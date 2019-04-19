/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:56:09 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:56:10 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"
#include "syntax_characters.h"
#include "heredoc.h"

#define LS_BOX_SIZE	4
#define LS_RAP_BOX_SIZE 7

static const t_ls_box	g_ls_box[LS_BOX_SIZE] =
{
	{ls_single_q_check, SINGLE_QUOTES_C},
	{ls_dobule_q_check, DOUBLE_QUOTES_C},
	{ls_backslash_check, BACKSLASH_C},
	{ls_semi_check, SEMICOLON_C},
};

static const t_ls_box	g_ls_rap_box[LS_RAP_BOX_SIZE] =
{
	{ls_single_q_check, SINGLE_QUOTES_C},
	{ls_dobule_q_check, DOUBLE_QUOTES_C},
	{ls_backslash_check, BACKSLASH_C},
	{ls_semi_check, SEMICOLON_C},
	{ls_rap_pipe, PIPE_C},
	{ls_rap_redir_in, REDIRECT_IN_C},
	{ls_rap_redir_out, REDIRECT_OUT_C},
};

static t_lexer_status	rl_ls_loop(t_line *ln, t_line_syntax *ls)
{
	t_lexer_status	res;
	uint8_t			iter;

	res = LS_OK;
	ls->i = -1;
	while (ln->line[++ls->i])
	{
		iter = -1;
		while (++iter < LS_BOX_SIZE)
			if (ln->line[ls->i] == g_ls_box[iter].c)
			{
				if ((res = g_ls_box[iter].f(ls, ln)))
					return (res);
				break ;
			}
		if (ls->i != SIZE_MAX && !ft_isspace(ln->line[ls->i]) &&
			ln->line[ls->i] != SEMICOLON_C)
			ls->semi_flag = true;
	}
	return (res);
}

static t_lexer_status	rl_ls_rap_loop(t_line *ln, t_line_syntax *ls)
{
	t_lexer_status	res;
	uint8_t			iter;

	res = LS_OK;
	--ls->i;
	while (ln->line[++ls->i])
	{
		iter = -1;
		while (++iter < LS_RAP_BOX_SIZE)
			if (ln->line[ls->i] == g_ls_rap_box[iter].c)
			{
				if ((res = g_ls_rap_box[iter].f(ls, ln)))
					return (res);
				break ;
			}
		if (ls->i != SIZE_MAX && !ft_isspace(ln->line[ls->i]) &&
			ln->line[ls->i] != SEMICOLON_C)
			ls->semi_flag = true;
	}
	return (res);
}

t_bool					rl_line_syntax_redir_and_pipes(t_line *ln,
							t_line_syntax *ls)
{
	t_lexer_status	res;

	res = rl_ls_rap_loop(ln, ls);
	if (res == LS_OK || res == LS_SYNTAX_ERR)
		return (true);
	return (false);
}

t_bool					rl_line_syntax(t_line *ln)
{
	t_line_syntax	ls;
	t_lexer_status	res;

	if (rl()->mod == M_SYNTAX_2)
		return (rl_line_syntax_redir_and_pipes(ln, &hd()->syntax_2));
	ft_bzero(&ls, sizeof(t_line_syntax));
	res = rl_ls_loop(ln, &ls);
	if (res == LS_SYNTAX_ERR)
		return (true);
	if (res == LS_OK)
	{
		rl()->mod = M_SYNTAX_2;
		return (rl_line_syntax_redir_and_pipes(ln, &hd()->syntax_2));
	}
	return (false);
}
