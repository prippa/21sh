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
	RL_SEMIX1 = -2,
	RL_SEMIX2,
	RL_Q,
	RL_DQ,
	RL_SLASH
};

int32_t				ls_backslash_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_dobule_q_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_single_q_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_semi_check(t_line_syntax *ls, t_line *ln);

#endif
