/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:41:46 by prippa            #+#    #+#             */
/*   Updated: 2019/04/04 20:42:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_SEARCH_H
# define HISTORY_SEARCH_H

# include "button_keys.h"

# define SEARCH_PROMPT "(reverse-i-search)`': "
# define FAIL_SEARCH_PROMPT "(failed reverse-i-search)`': "
# define STOP_CHR '`'

typedef struct		s_hs
{
	char			*search_str;
	t_list_elem		*h_current;
	t_bool			same_line_flag;
	size_t			start;
	char			reset_prompt[PROMPT_SIZE + 1];
	size_t			reset_prompt_size;
	t_mod			reset_mod;
}					t_hs;

t_hs				*hs(void);
void				rl_hs_new_mask(t_line *ln);
void				rl_hs_continue_revers_search(t_line *ln);
void				rl_history_init_new_prompt(const char *ss,
						const char *prompt);

#endif
