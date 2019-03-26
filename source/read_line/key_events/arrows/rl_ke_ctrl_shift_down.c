#include "button_keys.h"

int32_t		rl_ke_ctrl_shift_down(t_line *ln)
{
	uint16_t	col;

	if (ln->pc < ln->l_end)
	{
		col = rl()->w.ws_col;
		rl_del_from_line(ln, ln->pc + col, col, true);
		return (OK);
	}
	return (ERR);
}
