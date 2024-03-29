/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:12:06 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 17:42:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# include "shell.h"
# include <term.h>
# include <sys/ioctl.h>

# define RL_BUFF_SIZE 8
# define RL_BREAK 1
# define HISTORY_FILE_NAME ".21sh_history"

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
	t_list			history;
	t_list_elem		*current;
	char			*cur_line_buf;
	char			*path_to_hs_file;
}					t_history;

typedef struct		s_tc
{
	char			*ch;
	char			*up;
	char			*down;
	char			*cd;
	char			*cr;
	char			*cl;
	char			*u7;
}					t_tc;

typedef enum		e_mod
{
	M_DEFAULT,
	M_SEARCH,
	M_SYNTAX_2,
	M_HEREDOC
}					t_mod;

typedef struct		s_read_line
{
	t_hash_table	button_keys;
	t_line			ln;
	t_line			prev_ln;
	t_history		hs;
	int32_t			inh;
	struct winsize	w;
	char			prompt[PROMPT_SIZE + 1];
	size_t			prompt_size;
	t_mod			mod;
}					t_read_line;

t_read_line			*rl(void);
t_tc				*tc(void);
void				rl_init(void);
int32_t				rl_key_events(t_line *ln, const char buf[RL_BUFF_SIZE]);
t_bool				rl_history_search(t_line *ln, const char buf[RL_BUFF_SIZE]);

void				rl_make_tc_magic(const char *t);
void				rl_goto_x(uint16_t x);

void				rl_move_x(int32_t *x, size_t n, uint16_t col);
void				rl_clear_line(t_line *ln, uint16_t col);
void				rl_redraw_line(t_line *ln, uint16_t col);

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
