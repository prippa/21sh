#include "button_keys.h"

int32_t		rl_ke_end(t_line *ln)
{
	if (ln->l_cur_pos < ln->l_end)
	{
		rl_move_cursor_right(ln, ln->l_end - ln->l_cur_pos,
			rl()->w_size.ws_col);
		return (OK);
	}
	return (ERR);
}
