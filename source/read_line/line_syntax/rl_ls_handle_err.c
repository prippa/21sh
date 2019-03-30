/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_handle_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:51 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"
#include "messages.h"
#include "syntax_characters.h"

#define LS_ERR	SHELL_NAME ": syntax error: "
#define WTF_SEMICOLON_X1	LS_ERR "near unexpected token `;'"
#define WTF_SEMICOLON_X2	LS_ERR "near unexpected token `;;'"
#define WTF_EOF	"\n" LS_ERR "unexpected EOF while looking for matching `%c'"

#define QUOT_PROMPT			"quote> "
#define DQUOT_PROMPT		"dquote> "
#define SLASH_PROMPT		"> "

static const char	*g_syntax_err_messages[] =
{
	WTF_EOF,
	WTF_SEMICOLON_X2,
	WTF_SEMICOLON_X1
};

static const char	*g_new_prompts[] =
{
	QUOT_PROMPT,
	DQUOT_PROMPT,
	SLASH_PROMPT
};

static const char	g_wtf_eof_matching_characters[] =
{
	SINGLE_QUOTES_C,
	DOUBLE_QUOTES_C
};

static void	rl_ls_update_line(t_line *ln, t_bool new_line_f,
				const char *new_prompt, size_t np_size)
{
	if (new_line_f)
		rl_add_to_line(ln, "\n", rl()->w.ws_col, false);
	ln->l_start = ln->l_end;
	ln->pc = ln->l_start;
	ft_strcpy(rl()->prompt, new_prompt);
	rl()->prompt_size = np_size;
	ft_putstr_fd(new_prompt, STDIN_FILENO);
	ln->x = 0;
	rl_move_x(&ln->x, np_size, rl()->w.ws_col);
	rl_line_cpy(&rl()->prev_ln, &rl()->ln);
	rl()->hs.curent = NULL;
}

void		rl_ls_syntax_err(t_syntax_err serr)
{
	if (serr == LS_WTF_EOF)
	{
		PRINT_ERR(EXIT_FAILURE, g_syntax_err_messages[ABS(serr) - 1],
			g_wtf_eof_matching_characters[rl()->inhibitors_in_use - 1]);
	}
	else
	{
		PRINT_ERR(EXIT_FAILURE, g_syntax_err_messages[ABS(serr) - 1], NULL);
	}
}

void		rl_ls_new_prompt(t_line *ln, t_bool new_line_f, t_inhibitors inh)
{
	rl_ls_update_line(ln, new_line_f, g_new_prompts[inh - 1],
			ft_strlen(g_new_prompts[inh - 1]));
	rl()->inhibitors_in_use = inh;
}
