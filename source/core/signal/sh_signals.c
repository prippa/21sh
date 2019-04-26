/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sig_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:38 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <signal.h>

void		sh_sigint_reaction(void)
{
	ft_putchar_fd(ENDL, STDIN_FILENO);
	sh()->exec_code = SIGINT;
}

static void	sh_sig_handler(int32_t sig)
{
	if (sig == SIGINT)
	{
		sh_sigint_reaction();
		sh()->ok = false;
	}
}

void		sh_init_signals(void)
{
	signal(SIGINT, &sh_sig_handler);
	signal(SIGWINCH, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void		sh_reset_signals(void)
{
	signal(SIGINT, SIG_DFL);
}
