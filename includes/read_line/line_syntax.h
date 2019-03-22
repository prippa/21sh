#ifndef LINE_SYNTAX_H
# define LINE_SYNTAX_H

# include "read_line.h"

typedef struct		s_line_syntax
{
	t_bool			semi_flag;
	char			*line;
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

int32_t				ls_backslash_check(t_line_syntax *ls);
int32_t				ls_dobule_q_check(t_line_syntax *ls);
int32_t				ls_single_q_check(t_line_syntax *ls);
int32_t				ls_semi_check(t_line_syntax *ls);

#endif
