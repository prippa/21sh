#include "button_keys.h"

int32_t		rl_ke_home(t_line *ln)
{
	if (ln->l_cur_pos > ln->l_start)
	{
		rl_move_cursor_left(ln, ln->l_cur_pos, rl()->w_size.ws_col);
		return (OK);
	}
	return (ERR);
}
