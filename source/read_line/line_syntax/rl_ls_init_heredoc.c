#include "line_syntax.h"

static char		*rl_ls_get_word(t_line_syntax *ls, t_line *ln)
{

}

t_lexer_status	rl_ls_init_heredoc(t_line_syntax *ls, t_line *ln)
{
	ft_printf("[%s]\n", &ln->line[ls->i]);
	return (0);
}
