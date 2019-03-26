#include "button_keys.h"

int32_t		rl_ke_ctrl_k(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		rl_del_from_line(ln, ln->l_end, rl()->w.ws_col, true);
		return (OK);
	}
	return (ERR);
}
