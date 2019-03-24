#include "button_keys.h"

int32_t		rl_ke_ctrl_u(t_line *ln)
{
	size_t end;

	if (ln->l_cur_pos > ln->l_start)
	{
		end = ln->l_cur_pos;
		rl_ke_home(ln);
		rl_del_from_line(ln, end, rl()->w_size.ws_col, true);
		return (OK);
	}
	return (ERR);
}
