#include "button_keys.h"

int32_t		rl_ke_left(t_line *ln)
{
	if (ln->pc > ln->l_start)
	{
		ln->pc = rl_move_cursor_left(ln, ln->pc, 1, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t		rl_ke_right(t_line *ln)
{
	if (ln->pc < ln->l_end)
	{
		ln->pc = rl_move_cursor_right(ln, ln->pc, 1, rl()->w.ws_col);
		return (OK);
	}
	return (ERR);
}

int32_t			rl_ke_up(t_line *ln)
{
	t_read_line *r;

	r = rl();
	if (!r->hs.curent)
	{
		if (!r->hs.h_end)
			return (ERR);
		r->hs.curent = r->hs.h_end;
		GET_MEM(MALLOC_ERR, r->hs.cur_line_buf, ft_strdup_free,
			&r->hs.cur_line_buf, ln->line + ln->l_start);
		rl_history_move((char *)r->hs.curent->content, ln);
		return (OK);
	}
	else if (r->hs.h_start && r->hs.curent != r->hs.h_start)
	{
		r->hs.curent = r->hs.curent->prev;
		rl_history_move((char *)r->hs.curent->content, ln);
		return (OK);
	}
	return (ERR);
}

int32_t		rl_ke_down(t_line *ln)
{
	t_read_line *r;

	r = rl();
	if (r->hs.curent)
	{
		if (!r->hs.curent->next)
			rl_history_move(r->hs.cur_line_buf, ln);
		else
			rl_history_move((char *)r->hs.curent->next->content, ln);
		r->hs.curent = r->hs.curent->next;
		return (OK);
	}
	return (ERR);
}
