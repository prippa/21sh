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

#include "read_line.h"
#include "syntax_characters.h"

#define LS_CMD_SIZE	4

typedef int32_t		(*t_func_cmd)(t_line_syntax *ls);
static const		t_func_cmd	g_ls_cmd_f[LS_CMD_SIZE] =
{
	ls_single_q_check, ls_dobule_q_check, ls_backslash_check, ls_semi_check
};

static const char	g_ls_cmd_c[LS_CMD_SIZE] =
{
	SINGLE_QUOTES_C, DOUBLE_QUOTES_C, BACKSLASH_C, SEMICOLON_C
};

int32_t				rl_line_syntax(char **line)
{
	int32_t			res;
	uint8_t			iter;
	t_line_syntax	ls;

	res = OK;
	ft_bzero(&ls, sizeof(t_line_syntax));
	ls.i = -1;
	ls.line = *line;
	while (ls.line[++ls.i])
	{
		iter = -1;
		while (++iter < LS_CMD_SIZE)
			if (ls.line[ls.i] == g_ls_cmd_c[iter])
			{
				if ((res = g_ls_cmd_f[iter](&ls)))
					return (res);
				break ;
			}
		if (ls.i != SIZE_MAX && !ft_isspace(ls.line[ls.i]) &&
			ls.line[ls.i] != SEMICOLON_C)
			ls.semi_flag = true;
	}
	return (res);
}
