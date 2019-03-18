/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:12:06 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:12:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# include "shell.h"

#define RL_BUFF_SIZE 8

typedef struct	s_line_syntax
{
	t_bool		semi_flag;
}				t_line_syntax;

typedef struct	s_cursor
{
	int32_t		x;
	int32_t		y;
}				t_cursor;


typedef struct	s_read_line
{
	char		*line;
	size_t		i;
	t_bool		new_line_flag;
	t_bool		if_inhibitors_in_use_flag;
	t_cursor	cur;
}				t_read_line;

enum
{
	RL_SEMIX1 = -2,
	RL_SEMIX2,
	RL_Q,
	RL_DQ,
	RL_SLASH
};

t_read_line		*rl(void);
int32_t			rl_key_events(const char buf[RL_BUFF_SIZE]);

int32_t			rl_line_syntax(void);
int32_t			ls_backslash_check(t_line_syntax *ls);
int32_t			ls_dobule_q_check(t_line_syntax *ls);
int32_t			ls_single_q_check(t_line_syntax *ls);
int32_t			ls_semi_check(t_line_syntax *ls);
void			ls_print_info(int32_t key);

#endif