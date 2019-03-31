#ifndef HISTRORY_SEARCH_H
# define HISTRORY_SEARCH_H

# include "button_keys.h"

# define SEARCH_PROMPT "(reverse-i-search)`': "

typedef struct		s_hs
{
	char			*search_str;
	t_list2			*h_curent;
	t_list2			*h_end;
}					t_hs;

t_hs				*hs();
void				rl_hs_new_mask(t_line *ln);
void				rl_hs_continue_revers_search(t_line *ln);

#endif
