/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_syntax.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:06:38 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:06:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_SYNTAX_H
# define LINE_SYNTAX_H

# include "read_line.h"

typedef struct		s_line_syntax
{
	t_bool			semi_flag;
	size_t			i;
}					t_line_syntax;

enum
{
	LS_SYNTAX_ERR = -1,
	LS_OK,
	LS_NEW_PROMPT
};

enum
{
	LS_SEMIX1 = -2,
	LS_SEMIX2,
	LS_Q = 1,
	LS_DQ,
	LS_SLASH
};

int32_t				ls_backslash_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_dobule_q_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_single_q_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_semi_check(t_line_syntax *ls, t_line *ln);

void				rl_ls_syntax_err(int32_t key);
void				rl_ls_new_prompt(t_line *ln, t_bool new_line_f,
						int32_t key);

#endif
