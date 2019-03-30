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

int32_t		rl_ke_ctrl_shift_up(t_line *ln)
{
	size_t		end;
	uint16_t	col;

	if (ln->pc > ln->l_start)
	{
		col = rl()->w.ws_col;
		end = ln->pc;
		ln->pc = rl_move_cursor_left(ln, ln->pc, col, col);
		rl_del_from_line(ln, end, col, true);
		return (OK);
	}
	return (ERR);
}

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
