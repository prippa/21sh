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

typedef int32_t		(*t_func_check)(t_line_syntax *ls, t_line *ln);
typedef struct		s_ls_box
{
	t_func_check	f;
	char			c;
}					t_ls_box;

enum
{
	LS_SYNTAX_ERR = -1,
	LS_OK,
	LS_NEW_PROMPT
};

typedef enum		e_inhibitors
{
	LS_Q = 1,
	LS_DQ,
	LS_SLASH,
	LS_PIPE
}					t_inhibitors;

int32_t				ls_backslash_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_dobule_q_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_single_q_check(t_line_syntax *ls, t_line *ln);
int32_t				ls_semi_check(t_line_syntax *ls, t_line *ln);

int32_t				ls_rap_pipe(t_line_syntax *ls, t_line *ln);
int32_t				ls_rap_redir_in(t_line_syntax *ls, t_line *ln);
int32_t				ls_rap_redir_out(t_line_syntax *ls, t_line *ln);

void				rl_ls_syntax_err_wtf_eof(void);
void				rl_ls_syntax_err_wtf_token(const char *token);
void				rl_ls_new_prompt(t_line *ln, t_bool new_line_f,
						t_inhibitors inh);

#endif
