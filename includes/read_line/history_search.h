#ifndef HISTRORY_SEARCH_H
# define HISTRORY_SEARCH_H

# include "button_keys.h"

# define SEARCH_PROMPT "(reverse-i-search)`': "
# define FAIL_SEARCH_PROMPT "(failed reverse-i-search)`': "
# define STOP_CHR '`'

typedef struct		s_hs
{
	char			*search_str;
	t_list_elem		*h_curent;
	t_bool			same_line_flag;
	size_t			start;
	char			reset_prompt[PROMPT_SIZE + 1];
	size_t			reset_prompt_size;
}					t_hs;

t_hs				*hs(void);
void				rl_hs_new_mask(t_line *ln);
void				rl_hs_continue_revers_search(t_line *ln);
void				rl_history_init_new_prompt(const char *ss,
						const char *prompt);

#endif
