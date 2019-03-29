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
#include "read_line_signals.h"
#include "messages.h"

static void		rl_read(char buf[RL_BUFF_SIZE])
{
	rl_execute_aside_signals();
	rl_init_sig();
	ft_bzero(buf, RL_BUFF_SIZE);
	if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
		sh_fatal_err(READ_ERR);
	rl_init_sig_aside();
}

static void		rl_read_key(t_line *ln, char buf[RL_BUFF_SIZE])
{
	while (true)
	{
		rl_read(buf);
		if (!ln->line)
		{
			GET_MEM(MALLOC_ERR, ln->line, ft_strdup, EMPTY_STR);
		}
		if (ft_is_str_print(buf))
			rl_add_to_line(ln, buf, rl()->w.ws_col, true);
		else
			break ;
	}
}

static void		rl_loop(t_line *ln)
{
	char		buf[RL_BUFF_SIZE + 1];

	ft_bzero(buf, RL_BUFF_SIZE + 1);
	while (true)
	{
		rl_read_key(ln, buf);
		if (rl_key_events(ln, buf) == RL_BREAK)
			break ;
	}
}

char			*read_line(void)
{
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &sh()->new_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	rl_init();
	rl_loop(&rl()->ln);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &sh()->old_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	sh_init_sig_base();
	return (rl()->ln.line);
}
