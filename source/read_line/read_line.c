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

t_read_line		*rl(void)
{
	static t_read_line rl;

	return (&rl);
}

static void		read_line_loop(t_line *ln)
{
	char		buf[RL_BUFF_SIZE + 1];

	while (true)
	{
		rl()->new_line_flag = true;
		ft_bzero(buf, RL_BUFF_SIZE + 1);
		if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
			sh_fatal_err(READ_ERR);
		if (!ln->line && !(ln->line = ft_strdup("")))
			sh_fatal_err(MALLOC_ERR);
		if (rl_key_events(buf))
			break ;
		if (ft_is_str_print(buf))
		{
			// rl_join_str_to_line(buf);
			ft_putstr(buf);
		}
	}
}

static void		rl_init(void)
{
	ft_bzero(rl(), sizeof(t_read_line));
	ft_putstr(sh()->prompt);
	rl_get_pos(&rl()->ln.cursor_x, &rl()->ln.cursor_y);
	sleep(2);
	ft_printf("\nx - %d, y - %d\n", rl()->ln.cursor_x, rl()->ln.cursor_y);
	sleep(2);
	rl_goto(rl()->ln.cursor_x, rl()->ln.cursor_y);
	sleep(2);
	#include "builtin.h"
	sh_exit(NULL);
}

char			*read_line(void)
{
	sh_init_sig_rl();
	if ((tcsetattr(STDIN_FILENO, TCSANOW, sh()->new_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	rl_init();
	read_line_loop(&rl()->ln);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, sh()->old_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	sh_init_sig_base();
	return (rl()->ln.line);
}
