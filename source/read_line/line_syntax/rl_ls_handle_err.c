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
#define WTF_TOKEN LS_ERR "near unexpected token `%s'"
#define WTF_EOF "\n" LS_ERR "unexpected EOF while looking for matching `%c'"

static const char	g_wtf_eof_matching_characters[] =
{
	SINGLE_QUOTES_C,
	DOUBLE_QUOTES_C
};

void		rl_ls_syntax_err_wtf_eof(void)
{
	PRINT_ERR(EXIT_FAILURE, WTF_EOF,
		g_wtf_eof_matching_characters[rl()->inhibitors_in_use - 1]);
}

void		rl_ls_syntax_err_wtf_token(const char *token)
{
	PRINT_ERR(EXIT_FAILURE, WTF_TOKEN, token);
}
