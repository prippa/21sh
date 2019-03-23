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
	size_t			l_cur_pos;
	int32_t			x;
}					t_line;

typedef struct		s_read_line
{
	t_line			ln;
	t_bool			new_line_flag;
	t_bool			if_inhibitors_in_use_flag;
	struct winsize	w_size;
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
}					t_tc;

t_read_line			*rl(void);
t_tc				*tc(void);
void				rl_init(void);
void				rl_init_screen_col_row(void);
int32_t				rl_key_events(t_line *ln, const char buf[RL_BUFF_SIZE]);
void				rl_make_tc_magic(const char *t);
void				rl_determine_x(t_line *ln, size_t n, uint16_t col);
void				rl_goto_x(uint16_t x);
void				rl_redraw_line(t_line *ln, uint16_t col);

void				rl_move_cursor_up(size_t n);
void				rl_move_cursor_right(t_line *ln, size_t n, uint16_t col);
void				rl_move_cursor_left(t_line *ln, size_t n, uint16_t col);

void				rl_add_to_line(t_line *ln, const char *src,
						uint16_t col, t_bool print_to_term);
void				rl_del_from_line(t_line *ln, size_t end,
						uint16_t col, t_bool print_to_term);

int32_t				rl_line_syntax(t_line *ln);
void				ls_print_info(int32_t key);

#endif
