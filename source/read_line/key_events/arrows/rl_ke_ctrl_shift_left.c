#include "button_keys.h"

int32_t		rl_ke_ctrl_shift_left(t_line *ln)
{
	size_t	end;

	if (ln->pc > ln->l_start)
	{
		end = ln->pc;
		rl_ke_ctrl_left(ln);
		rl_del_from_line(ln, end, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}
