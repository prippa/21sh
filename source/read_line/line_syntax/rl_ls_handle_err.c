/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ls_handle_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:51 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_syntax.h"
#include "info.h"
#include "syntax_characters.h"

#define LS_ERR SHELL_NAME ": syntax error: "
#define WTF_TOKEN LS_ERR "near unexpected token `%s'"
#define WTF_EOF LS_ERR "unexpected end of file"
#define WTF_EOF_Q SHELL_NAME ": unexpected EOF while looking for matching `%c'"

static const char	g_wtf_eof_matching_characters[] =
{
	SINGLE_QUOTES_C,
	DOUBLE_QUOTES_C
};

void	rl_ls_syntax_err_wtf_eof_for_quote(void)
{
	sh_print_err(EXIT_FAILURE, MSG(WTF_EOF_Q,
		g_wtf_eof_matching_characters[rl()->inh - 1]));
}

void	rl_ls_syntax_err_wtf_token(const char *token)
{
	sh_print_err(EXIT_FAILURE, MSG(WTF_TOKEN, token));
}

void	rl_ls_syntax_err_wtf_eof(void)
{
	sh_print_err(EXIT_FAILURE, MSG(WTF_EOF, NULL));
}
