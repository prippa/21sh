/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:16:17 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 13:16:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "messages.h"

static void		read_line_loop(t_line *ln)
{
	char		buf[RL_BUFF_SIZE + 1];

	while (true)
	{
		rl()->new_line_flag = true;
		ft_bzero(buf, RL_BUFF_SIZE + 1);
		if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
			sh_fatal_err(READ_ERR);
		if (!ln->line)
		{
			GET_MEM(MALLOC_ERR, ln->line, ft_strdup, EMPTY_STR);
		}
		if (rl_key_events(ln, buf) == RL_BREAK)
			break ;
	}
}

char			*read_line(void)
{
	rl_init();
	sh_init_sig_rl();
	if ((tcsetattr(STDIN_FILENO, TCSANOW, sh()->new_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	read_line_loop(&rl()->ln);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, sh()->old_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	sh_init_sig_base();
	return (rl()->ln.line);
}
