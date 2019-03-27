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
# include <term.h>
# include <sys/ioctl.h>

# define RL_BUFF_SIZE 8
# define RL_BREAK 1

typedef struct		s_line
{
	char			*line;
	size_t			l_start;
	size_t			l_end;
	size_t			pc;
	int32_t			x;
}					t_line;

typedef struct		s_history
{
	t_list2			*h_start;
	t_list2			*h_end;
	t_list2			*curent;
	char			*cur_line_buf;
}					t_history;

typedef struct		s_read_line
{
	t_line			ln;
	t_line			prev_ln;
	t_history		hs;
	int32_t			inhibitors_in_use;
	struct winsize	w;
	char			prompt[PROMPT_SIZE + 1];
	size_t			prompt_size;
}					t_read_line;

typedef int32_t		(*t_func)(t_line *ln);
typedef struct		s_event
{
	t_func			f;
	uint64_t		key;
}					t_event;

typedef struct		s_tc
{
	char			*le;
	char			*nd;
	char			*down;
	char			*up;
	char			*cd;
	char			*cr;
	char			*ch;
	char			*cl;
	char			*u7;
}					t_tc;

t_read_line			*rl(void);
t_tc				*tc(void);
void				rl_init(void);
int32_t				rl_key_events(t_line *ln, const char buf[RL_BUFF_SIZE]);

void				rl_make_tc_magic(const char *t);
void				rl_goto_x(uint16_t x);

void				rl_determine_x(t_line *ln, size_t n, uint16_t col);
int32_t				rl_get_x_pos(const char *u7_str);
void				rl_clear_line(t_line *ln, uint16_t col);
void				rl_redraw_line(t_line *ln, uint16_t col);

void				rl_move_cursor_up(size_t n);
size_t				rl_move_cursor_right(t_line *ln, size_t pc,
						size_t n, uint16_t col);
size_t				rl_move_cursor_left(t_line *ln, size_t pc,
						size_t n, uint16_t col);

void				rl_add_to_line(t_line *ln, const char *src,
						uint16_t col, t_bool print_to_term);
void				rl_del_from_line(t_line *ln, size_t end,
						uint16_t col, t_bool print_to_term);
void				rl_line_del(t_line *ln);
void				rl_line_cpy(t_line *dst, t_line *src);

t_bool				rl_line_syntax(t_line *ln);
void				rl_history_add(const char *line);
void				rl_history_move(const char *line, t_line *ln);

#endif
