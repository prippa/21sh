/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 11:54:43 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 20:08:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_COMPLETION_H
# define AUTO_COMPLETION_H

# include "button_keys.h"

typedef struct		s_match
{
	char			*name;
	int32_t			color;
}					t_match;

typedef struct		s_ac
{
	t_list			matches;
	char			*main_match;
}					t_ac;

t_ac			*ac(void);

t_list			rl_t_get_cmd_matches(const char *bc);
t_list			rl_t_get_path_matches(char **bc);
int32_t			tab_process_matches(const t_list_elem *m,
					size_t len, t_line *ln);

#endif
