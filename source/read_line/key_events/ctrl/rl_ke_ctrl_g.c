#include "button_keys.h"

int32_t		rl_ke_ctrl_g(t_line *ln)
{
	if (!ft_is_str_empty(ln->line))
	{
		rl_ke_home(ln);
		rl_del_from_line(ln, ln->l_end, rl()->w_size.ws_col, true);
		return (OK);
	}
	return (ERR);
}
