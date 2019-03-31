#include "history_search.h"

static void		rl_hs_nm_init_new_prompt(const char *ss)
{
	char	*new_prompt;

	GET_MEM(MALLOC_ERR, new_prompt, ft_strdup, SEARCH_PROMPT);
	GET_MEM(MALLOC_ERR, new_prompt, ft_strinsert_free,
		&new_prompt, ss,
		(ft_strchr(new_prompt, '`') + 1) - new_prompt);
	ft_strcpy(rl()->prompt, new_prompt);
	rl()->prompt_size = ft_strlen(ss) + ft_strlen(SEARCH_PROMPT);
	ft_strdel(&new_prompt);
}

void			rl_hs_new_mask(t_line *ln)
{
	rl_clear_line(ln, rl()->w.ws_col);
	rl_hs_nm_init_new_prompt(hs()->search_str);
	hs()->h_curent = hs()->h_end;
	rl_redraw_line(ln, rl()->w.ws_col);
	rl_hs_continue_revers_search(ln);
}
