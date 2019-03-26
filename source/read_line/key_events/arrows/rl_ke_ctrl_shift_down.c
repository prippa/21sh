#include "button_keys.h"

int32_t		rl_ke_ctrl_shift_down(t_line *ln)
{
	size_t		end;
	uint16_t	col;

	if (ln->pc < ln->l_end)
	{
		col = rl()->w.ws_col;
		end = rl_move_cursor_right(ln, ln->pc, col, col);
		rl_del_from_line(ln, end, col, true);
		return (OK);
	}
	return (ERR);
}
