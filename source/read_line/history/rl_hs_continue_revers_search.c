#include "history_search.h"

static t_bool	rl_hs_crs_check(const char *line, t_line *ln)
{
	
	return (false);
}

void			rl_hs_continue_revers_search(t_line *ln)
{
	while (hs()->h_curent)
	{
		if (rl_hs_crs_check((char *)hs()->h_curent->content, ln))
			hs()->h_curent = hs()->h_curent->next;
		else
			break ;
	}
}
