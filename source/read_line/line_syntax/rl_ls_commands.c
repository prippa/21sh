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

int32_t	ls_backslash_check(t_line_syntax *ls, t_line *ln)
{
	if (!ln->line[++ls->i])
	{
		GET_MEM(MALLOC_ERR, ln->line, ft_strsub_free,
			&ln->line, 0, ls->i - 1);
		rl()->new_line_flag = false;
		return (RL_SLASH);
	}
	return (OK);
}

int32_t	ls_dobule_q_check(t_line_syntax *ls, t_line *ln)
{
	while (true)
	{
		if (!ln->line[++ls->i] ||
			(ln->line[ls->i] == BACKSLASH_C && !ln->line[ls->i + 1]))
		{
			if (ln->line[ls->i] == BACKSLASH_C && !ln->line[ls->i + 1])
			{
				// rl_add_to_line(rl()->ln, )
				GET_MEM(MALLOC_ERR, ln->line, ft_strsub_free,
					&ln->line, 0, ls->i);
				rl()->new_line_flag = false;
			}
			return (RL_DQ);
		}
		if (ln->line[ls->i] == BACKSLASH_C)
			++ls->i;
		else if (ln->line[ls->i] == DOUBLE_QUOTES_C)
			return (OK);
	}
}

int32_t	ls_single_q_check(t_line_syntax *ls, t_line *ln)
{
	while (true)
	{
		if (!ln->line[++ls->i])
			return (RL_Q);
		if (ln->line[ls->i] == SINGLE_QUOTES_C)
			return (OK);
	}
}

int32_t	ls_semi_check(t_line_syntax *ls, t_line *ln)
{
	if (!ls->semi_flag)
	{
		if (ln->line[ls->i + 1] == SEMICOLON_C || (ls->i &&
			ln->line[ls->i - 1] == SEMICOLON_C))
			return (RL_SEMIX2);
		else
			return (RL_SEMIX1);
	}
	ls->semi_flag = false;
	return (OK);
}
