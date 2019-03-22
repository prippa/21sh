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
#include "messages.h"
#include "syntax_characters.h"
#include "builtin.h"

int32_t	ls_backslash_check(t_line_syntax *ls)
{
	if (!ls->line[++ls->i])
	{
		GET_MEM(MALLOC_ERR, ls->line, ft_strsub_free,
			&ls->line, 0, ls->i - 1);
		rl()->new_line_flag = false;
		return (RL_SLASH);
	}
	return (OK);
}

int32_t	ls_dobule_q_check(t_line_syntax *ls)
{
	while (true)
	{
		if (!ls->line[++ls->i] ||
			(ls->line[ls->i] == BACKSLASH_C && !ls->line[ls->i + 1]))
		{
			if (ls->line[ls->i] == BACKSLASH_C && !ls->line[ls->i + 1])
			{
				GET_MEM(MALLOC_ERR, ls->line, ft_strsub_free,
					&ls->line, 0, ls->i);
				rl()->new_line_flag = false;
			}
			return (RL_DQ);
		}
		if (ls->line[ls->i] == BACKSLASH_C)
			++ls->i;
		else if (ls->line[ls->i] == DOUBLE_QUOTES_C)
			return (OK);
	}
}

int32_t	ls_single_q_check(t_line_syntax *ls)
{
	while (true)
	{
		if (!ls->line[++ls->i])
			return (RL_Q);
		if (ls->line[ls->i] == SINGLE_QUOTES_C)
			return (OK);
	}
}

int32_t	ls_semi_check(t_line_syntax *ls)
{
	if (!ls->semi_flag)
	{
		if (ls->line[ls->i + 1] == SEMICOLON_C || (ls->i &&
			ls->line[ls->i - 1] == SEMICOLON_C))
			return (RL_SEMIX2);
		else
			return (RL_SEMIX1);
	}
	ls->semi_flag = false;
	return (OK);
}
