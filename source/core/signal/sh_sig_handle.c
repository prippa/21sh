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

#include "shell.h"
#include "read_line.h"
#include <signal.h>

void		sh_sig_handle_rl(int sig)
{
	if (sig == SIGINT)
	{
		free(rl()->ln.line);
		ft_bzero(rl(), sizeof(t_read_line));
		sh()->exec_code = SIGINT;
		ft_putchar_fd('\n', STDIN_FILENO);
		sh_update_prompt(false);
		ft_putstr(sh()->prompt);
	}
}

void		sh_sig_handle_base(int sig)
{
	if (sig == SIGINT)
	{
		sh()->exec_code = SIGINT;
		ft_putchar_fd('\n', STDIN_FILENO);
		sh_update_prompt(false);
		ft_putstr(sh()->prompt);
	}
}

void		sh_sig_handle_incase(int sig)
{
	if (sig == SIGINT)
	{
		sh()->exec_code = SIGINT;
		sh()->ok = false;
		ft_putchar_fd('\n', STDIN_FILENO);
	}
}
