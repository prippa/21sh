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

#define LS_BOX_SIZE	4

static const t_ls_box	g_ls_box[LS_BOX_SIZE] =
{
	{ls_single_q_check, SINGLE_QUOTES_C},
	{ls_dobule_q_check, DOUBLE_QUOTES_C},
	{ls_backslash_check, BACKSLASH_C},
	{ls_semi_check, SEMICOLON_C},
};

static int32_t		rl_ls_loop(t_line *ln, t_line_syntax *ls)
{
	int32_t			res;
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

t_bool				rl_line_syntax(t_line *ln)
{
	t_line_syntax	ls;
	int32_t			res;

	ft_bzero(&ls, sizeof(t_line_syntax));
	res = rl_ls_loop(ln, &ls);
	if (res == LS_OK || res == LS_SYNTAX_ERR)
		return (true);
	return (false);
}
