/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"

t_shell		*sh(void)
{
	static t_shell sh;

	return (&sh);
}

static void	sh_init_fd(void)
{
	sh()->fd[STDIN_FILENO] = dup(STDIN_FILENO);
	sh()->fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	sh()->fd[STDERR_FILENO] = dup(STDERR_FILENO);
	if (sh()->fd[STDIN_FILENO] == ERR ||
		sh()->fd[STDOUT_FILENO] == ERR ||
		sh()->fd[STDERR_FILENO] == ERR)
		sh_fatal_err(DUP_FAILED);
}

void		sh_init(void)
{
	g_fef = &sh_fatal_err;
	sh_init_term();
	sh_init_env();
	sh_init_read_line();
	sh_init_line_parser();
	sh_init_fd();
	sh()->ok = true;
	sh_update_prompt(true);
	sh_init_sig_base();
}
