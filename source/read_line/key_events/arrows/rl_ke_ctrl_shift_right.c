#include "button_keys.h"

int32_t		rl_ke_ctrl_shift_right(t_line *ln)
{
	size_t	end;

	if (ln->pc < ln->l_end)
	{
		end = ft_get_right_word(ln->line, ln->pc, ln->l_end);
		rl_del_from_line(ln, ln->pc + end, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}
