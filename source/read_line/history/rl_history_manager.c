/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:24:06 by prippa            #+#    #+#             */
/*   Updated: 2019/03/25 14:24:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_search.h"

t_hs		*hs(void)
{
	static t_hs	hs;

	return (&hs);
}

static void	rl_history_push_and_write(char *l)
{
	size_t		l_len;
	char		*msg;
	int32_t		fd;

	l_len = ft_strlen(l);
	if (rl()->hs.path_to_hs_file)
	{
		fd = open(rl()->hs.path_to_hs_file, OPEN_RDWR_APPEND_FLAGS,
			OPEN_CREATE_RW_RIGHTS);
		msg = MSG("%s\n", l);
		write(fd, msg, l_len + 1);
		ft_strdel(&msg);
		close(fd);
	}
	LST_PUSH_BACK_REF(&rl()->hs.history, l, l_len);
}

void		rl_history_add(const char *line)
{
	char		*l;
	char		*chr;

	if (ft_is_str_space(line) || ft_is_str_empty(line) ||
		(rl()->hs.history.end &&
		ft_strequ((char *)rl()->hs.history.end->content, line)))
		return ;
	if ((chr = ft_strchr(line, ENDL)))
		l = ft_strsub(line, 0, chr - line);
	else
		l = ft_strdup(line);
	rl_history_push_and_write(l);
}

void		rl_history_move(const char *line, t_line *ln)
{
	rl_ke_ctrl_g(ln);
	rl_add_to_line(ln, line, rl()->w.ws_col, true);
}

void		rl_history_init_new_prompt(const char *ss, const char *prompt)
{
	char	*new_prompt;

	new_prompt = ft_strdup(prompt);
	ft_strinsert_free(&new_prompt, ss,
		(ft_strchr(new_prompt, STOP_CHR) + 1) - new_prompt);
	ft_strcpy(rl()->prompt, new_prompt);
	rl()->prompt_size = ft_strlen(ss) + ft_strlen(prompt);
	ft_strdel(&new_prompt);
}
