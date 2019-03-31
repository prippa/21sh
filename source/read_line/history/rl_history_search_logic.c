#include "history_search.h"

static t_bool	rl_hs_crs_start_compare(const char *line,
					const char *ss, size_t ss_len)
{
	while (true)
	{
		if (!hs()->start)
			return (false);
		else
			--hs()->start;
		if (ft_strnstr(line + hs()->start, ss, ss_len))
			break ;
	}
	return (true);
}

static t_bool	rl_hs_crs_new_line(t_line *ln, const char *line,
					size_t line_len, size_t ss_len)
{
	if (line_len < ss_len)
		return (true);
	hs()->start = line_len;
	if (rl_hs_crs_start_compare(line, hs()->search_str, ss_len))
	{
		rl_ke_ctrl_g(ln);
		rl_add_to_line(ln, line, rl()->w.ws_col, true);
		ln->pc = rl_move_cursor_left(ln, ln->pc,
			ln->pc - hs()->start, rl()->w.ws_col);
		hs()->same_line_flag = true;
	}
	return (hs()->same_line_flag ? false : true);
}

static t_bool	rl_hs_crs_check(const char *line, t_line *ln)
{
	size_t	line_len;
	size_t	ss_len;

	line_len = ft_strlen(line);
	ss_len = ft_strlen(hs()->search_str);
	if (hs()->same_line_flag)
	{
		if (rl_hs_crs_start_compare(line, hs()->search_str, ss_len))
		{
			ln->pc = rl_move_cursor_left(ln, ln->pc,
				ln->pc - hs()->start, rl()->w.ws_col);
		}
		else
			hs()->same_line_flag = false;
		return (hs()->same_line_flag ? false : true);
	}
	else
		return (rl_hs_crs_new_line(ln, line, line_len, ss_len));
}

void			rl_hs_continue_revers_search(t_line *ln)
{
	if (*hs()->search_str)
	{
		while (hs()->h_curent)
		{
			if (rl_hs_crs_check((char *)hs()->h_curent->content, ln))
				hs()->h_curent = hs()->h_curent->prev;
			else
				break ;
		}
	}
	if (!hs()->h_curent || !*hs()->search_str)
	{
		rl_clear_line(ln, rl()->w.ws_col);
		rl_history_init_new_prompt(hs()->search_str, FAIL_SEARCH_PROMPT);
		rl_redraw_line(ln, rl()->w.ws_col);
	}
}

void			rl_hs_new_mask(t_line *ln)
{
	rl_clear_line(ln, rl()->w.ws_col);
	rl_history_init_new_prompt(hs()->search_str, SEARCH_PROMPT);
	rl_redraw_line(ln, rl()->w.ws_col);
	hs()->h_curent = rl()->hs.h_end;
	hs()->same_line_flag = false;
	rl_hs_continue_revers_search(ln);
}
