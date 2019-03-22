/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sig_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:38 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include <signal.h>
#include <sys/ioctl.h>

void		sh_sig_handle_rl(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		sh()->exec_code = SIGINT;
		sh_update_prompt(false);
		free(rl()->ln.line);
		rl_init();
	}
	if (sig == SIGWINCH)
	{
		rl_move_cursor_up((P_SIZE + rl()->ln.line_len) / rl()->w.ws_col);
		rl_make_tc_magic(tc()->cr);
		rl_make_tc_magic(tc()->cd);
		ioctl(STDIN_FILENO, TIOCGWINSZ, &rl()->w);
		rl_redraw_line(&rl()->ln);
	}
}

void		sh_sig_handle_base(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		sh()->exec_code = SIGINT;
		sh_update_prompt(false);
		ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	}
}

void		sh_sig_handle_incase(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		sh()->exec_code = SIGINT;
		sh()->ok = false;
	}
}
