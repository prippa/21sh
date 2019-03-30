#include "button_keys.h"
#include "line_syntax.h"
#include "builtin.h"

int32_t		rl_ke_ctrl_d(t_line *ln)
{
	if (ft_is_str_empty(ln->line))
		sh_exit(NULL);
	else if (rl()->inhibitors_in_use && ln->l_start == ln->l_end)
	{
		rl_ls_syntax_err(LS_WTF_EOF);
		return (RL_BREAK);
	}
	return (ERR);
}

int32_t		rl_ke_ctrl_a(t_line *ln)
{
	return (rl_ke_home(ln));
}

int32_t		rl_ke_ctrl_e(t_line *ln)
{
	return (rl_ke_end(ln));
}

int32_t		rl_ke_ctrl_l(t_line *ln)
{
	rl_make_tc_magic(tc()->cl);
	rl_redraw_line(ln, rl()->w.ws_col);
	return (OK);
}

int32_t		rl_ke_ctrl_h(t_line *ln)
{
	t_line		tmp;

	ft_bzero(&tmp, sizeof(t_line));
	rl_line_cpy(&tmp, ln);
	rl_line_cpy(ln, &rl()->prev_ln);
	rl_line_cpy(&rl()->prev_ln, &tmp);
	rl_clear_line(&tmp, rl()->w.ws_col);
	rl_redraw_line(ln, rl()->w.ws_col);
	rl_line_del(&tmp);
	return (OK);
}
