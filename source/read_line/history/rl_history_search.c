#include "history_search.h"

t_hs			*hs()
{
	static t_hs	hs;

	return (&hs);
}

static void		rl_hs_new_mask_add(t_line *ln, const char *new_data)
{
	if (ft_strlen(new_data) + rl()->prompt_size > PROMPT_SIZE)
		return ;
	GET_MEM(MALLOC_ERR, hs()->search_str, ft_strjoin_free,
		&hs()->search_str, new_data,
		ft_strlen(hs()->search_str), ft_strlen(new_data));
	rl_hs_new_mask(ln);
}

static void		rl_hs_new_mask_del(t_line *ln)
{
	if (!ft_is_str_empty(hs()->search_str))
	{
		GET_MEM(MALLOC_ERR, hs()->search_str, ft_strsub_free,
			&hs()->search_str, 0, ft_strlen(hs()->search_str) - 1);
		rl_hs_new_mask(ln);
	}
}

static void		rl_hs_set_default_mod(t_line *ln)
{
	rl()->mod = M_DEFAULT;
	rl_clear_line(ln, rl()->w.ws_col);
	ft_strcpy(rl()->prompt, sh()->prompt);
	rl()->prompt_size = PROMPT_ADS + ft_strlen(sh()->curent_path);
	rl_redraw_line(ln, rl()->w.ws_col);
	ft_strdel(&hs()->search_str);
}

t_bool			rl_history_search(t_line *ln, const char buf[RL_BUFF_SIZE])
{
	uint64_t key;

	ft_memcpy(&key, buf, RL_BUFF_SIZE);
	if (!hs()->search_str)
	{
		GET_MEM(MALLOC_ERR, hs()->search_str, ft_strdup, EMPTY_STR);
		hs()->h_curent = rl()->hs.h_end;
		hs()->h_end = rl()->hs.h_end;
	}
	if (ft_is_str_print(buf))
		rl_hs_new_mask_add(ln, buf);
	else if (key == KEY_CTRL_R)
		rl_hs_continue_revers_search(ln);
	else if (key == KEY_BACKSPACE)
		rl_hs_new_mask_del(ln);
	else
	{
		rl_hs_set_default_mod(ln);
		return (false);
	}
	return (true);
}
