/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:07:42 by prippa            #+#    #+#             */
/*   Updated: 2019/04/17 14:07:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "messages.h"

static void	lp_pipe_logic_in(t_line_parser *lp, int32_t pipe_fd[2])
{
	if (!lp->busy_in)
	{
		lp->fd_in = pipe_fd[STDIN_FILENO];
		lp->pipe_flag = true;
	}
}

static void	lp_pipe_logic_out(t_line_parser *lp, int32_t pipe_fd[2])
{
	if (isatty(STDOUT_FILENO))
	{
		if (dup2(pipe_fd[STDOUT_FILENO], STDOUT_FILENO) == ERR)
			sh_fatal_err(DUP2_FAILED);
	}
	close(pipe_fd[STDOUT_FILENO]);
}

void		lp_pipe(t_line_parser *lp)
{
	int32_t		pipe_fd[2];

	if (pipe(pipe_fd) == ERR)
		sh_fatal_err(PIPE_FAILED);
	lp_pipe_logic_in(lp, pipe_fd);
	lp_pipe_logic_out(lp, pipe_fd);
	lp_push_command(lp);
	++lp->i;
}
