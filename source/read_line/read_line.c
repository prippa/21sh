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

static void		read_line_loop(void)
{
	int32_t		ke_res;
	char		buf[RL_BUFF_SIZE + 1];

	while (true)
	{
		rl()->new_line_flag = true;
		ft_bzero(buf, RL_BUFF_SIZE + 1);
		if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
			sh_fatal_err(READ_ERR);
		if (!rl()->line && !(rl()->line = ft_strdup("")))
			sh_fatal_err(MALLOC_ERR);
		if ((ke_res = rl_key_events(buf)) == RL_BREAK)
			break ;
		else if (ke_res == RL_CONTINUE)
			continue ;
		rl_join_str_to_line(buf);
		ft_putstr(buf);
	}
}

char			*read_line(void)
{
	ft_bzero(rl(), sizeof(t_read_line));
	ft_putstr(sh()->prompt);
	signal(SIGINT, sh_handle_sigint_rl);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, sh()->new_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	read_line_loop();
	if ((tcsetattr(STDIN_FILENO, TCSANOW, sh()->old_settings)) == ERR)
		sh_fatal_err(TCSETATTR_FAILED);
	signal(SIGINT, sh_handle_sigint_base);
	return (rl()->line);
}
