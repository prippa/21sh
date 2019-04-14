#include "line_syntax.h"

static const char	*g_new_prompts[] =
{
	"quote> ",
	"dquote> ",
	"> ",
	"pipe> "
};

static void	rl_ls_update_line(t_line *ln, t_bool new_line_f,
				const char *new_prompt, size_t np_size)
{
	if (new_line_f)
		rl_add_to_line(ln, "\n", rl()->w.ws_col, false);
	ln->l_start = ln->l_end;
	ln->pc = ln->l_start;
	ft_strcpy(rl()->prompt, new_prompt);
	rl()->prompt_size = np_size;
	ft_putstr_fd(new_prompt, STDIN_FILENO);
	ln->x = 0;
	rl_move_x(&ln->x, np_size, rl()->w.ws_col);
	rl_line_cpy(&rl()->prev_ln, &rl()->ln);
	rl()->hs.curent = NULL;
}

void		rl_ls_new_prompt(t_line *ln, t_bool new_line_f, t_inhibitors inh)
{
	rl_ls_update_line(ln, new_line_f, g_new_prompts[inh - 1],
			ft_strlen(g_new_prompts[inh - 1]));
	rl()->inhibitors_in_use = inh;
}
