/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:35:36 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:35:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "heredoc.h"

t_read_line		*rl(void)
{
	static t_read_line rl;

	return (&rl);
}

t_tc			*tc(void)
{
	static t_tc tc;

	return (&tc);
}

static void		rl_check_if_not_new_line(void)
{
	char	buf[42 + 1];
	char	*chr;

	ft_bzero(buf, 42);
	write(STDIN_FILENO, tc()->u7, 4);
	if (read(STDIN_FILENO, buf, 42) == ERR)
		sh_fatal_err(READ_ERR);
	if ((chr = ft_strchr(buf, ';')))
	{
		if (ft_atoi(++chr) - 1)
			ft_dprintf(STDIN_FILENO, "%s%~c\n", BOLD, CT_BACK, C_WHITE, '%');
	}
}

void			rl_init(void)
{
	rl_check_if_not_new_line();
	rl()->hs.curent = NULL;
	ft_bzero(&rl()->ln, sizeof(t_line));
	rl()->ln.line = ft_strdup(EMPTY_STR);
	rl()->inhibitors_in_use = false;
	ft_strcpy(rl()->prompt, sh()->prompt);
	rl()->prompt_size = PROMPT_ADS + ft_strlen(sh()->curent_path);
	ft_putstr_fd(rl()->prompt, STDIN_FILENO);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &rl()->w);
	rl_move_x(&rl()->ln.x, rl()->prompt_size, rl()->w.ws_col);
	rl_line_cpy(&rl()->prev_ln, &rl()->ln);
	rl()->mod = M_DEFAULT;
	LST_DEL(&hd()->heredoc);
	ft_strdel(&hd()->heredoc_delimiter);
	ft_bzero(&hd()->syntax_2, sizeof(t_line_syntax));
}
