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
#include "info.h"

static void		rl_read(char buf[RL_BUFF_SIZE])
{
	rl_execute_aside_signals(&rl_sig_handle);
	rl_init_sig();
	ft_bzero(buf, RL_BUFF_SIZE);
	if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
		g_fef(READ_ERR);
	rl_init_sig_aside();
}

static void		rl_read_key(t_line *ln, char buf[RL_BUFF_SIZE])
{
	while (true)
	{
		rl_read(buf);
		if (rl()->mod == M_SEARCH)
		{
			if (!rl_history_search(ln, buf))
				break ;
		}
		else if (ft_is_str_print(buf))
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
		g_fef(TCSETATTR_FAILED);
	rl_init();
	rl_loop(&rl()->ln);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &sh()->old_settings)) == ERR)
		g_fef(TCSETATTR_FAILED);
	sh_init_signals();
	return (rl()->ln.line);
}
