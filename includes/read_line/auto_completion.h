/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 11:54:43 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 17:32:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_COMPLETION_H
# define AUTO_COMPLETION_H

# include "button_keys.h"

typedef struct	s_match
{
	char		*name;
	int32_t		color;
	int32_t		color_type;
}				t_match;
# define MATCH(n, c, ct) &(t_match){.name = n, .color = c, .color_type = ct}

typedef struct	s_ac
{
	t_list		matches;
	char		*input_word;
	char		*tmp_str;
	int32_t		color;
	int32_t		color_type;
}				t_ac;

t_ac			*ac(void);
void			rl_t_push_match(const char *f, size_t f_len,
					int32_t f_color, int32_t f_color_type);
void			rl_t_del_match_list(void *content, size_t content_size);

t_bool			rl_t_get_cmd_input_word(t_line *ln);
void			rl_t_get_cmd_matches(void);

t_bool			rl_t_get_path_input_word(t_line *ln);
void			rl_t_get_path_matches(void);

int32_t			rl_t_process_matches(t_line *ln);

void			rl_t_print_matches(t_line *ln, size_t width);

#endif
