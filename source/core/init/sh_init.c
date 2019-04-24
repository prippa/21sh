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

static void	sh_init_std_fd(void)
{
	if (dup2(STDIN_FILENO, TERM_STDIN) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(STDOUT_FILENO, TERM_STDOUT) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(STDERR_FILENO, TERM_STDERR) == ERR)
		sh_fatal_err(DUP2_FAILED);
	sh()->std_fd[STDIN_FILENO] = TERM_STDIN;
	sh()->std_fd[STDOUT_FILENO] = TERM_STDOUT;
	sh()->std_fd[STDERR_FILENO] = TERM_STDERR;
}

void		sh_init(void)
{
	g_fef = &sh_fatal_err;
	sh_init_term();
	sh_init_env();
	sh_init_read_line();
	sh_init_line_parser();
	sh_init_std_fd();
	sh()->ok = true;
	sh_update_curent_dir_name();
	sh_update_prompt(true);
	sh_init_sig_base();
}
