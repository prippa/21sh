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

#define LS_ERR				SHELL_NAME ": syntax error : "
#define WTF_SEMICOLON_X1	LS_ERR "near unexpected token `;'"
#define WTF_SEMICOLON_X2	LS_ERR "near unexpected token `;;'"

#define QUOT_PROMPT			"quote> "
#define DQUOT_PROMPT		"dquote> "
#define SLASH_PROMPT		"> "

static const char	*g_syntax_err_messages[] =
{
	WTF_SEMICOLON_X2,
	WTF_SEMICOLON_X1
};

static const char	*g_new_prompts[] =
{
	QUOT_PROMPT,
	DQUOT_PROMPT,
	SLASH_PROMPT
};

static void	rl_ls_update_line(t_line *ln, t_bool new_line_f,
				const char *new_prompt, size_t np_size)
{
	t_read_line *r;

	r = rl();
	if (new_line_f)
		rl_add_to_line(ln, "\n", r->w.ws_col, false);
	ln->l_start = ln->l_end;
	ln->pc = ln->l_start;
	ft_strcpy(sh()->prompt, new_prompt);
	r->prompt_size = np_size;
	r->if_inhibitors_in_use_flag = true;
	ln->x = 0;
	rl_determine_x(ln, np_size, r->w.ws_col);
	ft_putstr_fd(new_prompt, STDIN_FILENO);
	r->hs.curent = NULL;
}

void		rl_ls_syntax_err(int32_t key)
{
	PRINT_ERR(EXIT_FAILURE, g_syntax_err_messages[ABS(key) - 1], NULL);
}

void		rl_ls_new_prompt(t_line *ln, t_bool new_line_f, int32_t key)
{
	rl_ls_update_line(ln, new_line_f, g_new_prompts[key - 1],
			ft_strlen(g_new_prompts[key - 1]));
}
