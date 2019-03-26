#include "button_keys.h"

int32_t		rl_ke_ctrl_l(t_line *ln)
{
	rl_make_tc_magic(tc()->cl);
	rl_redraw_line(ln, rl()->w.ws_col);
	return (OK);
}
