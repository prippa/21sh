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
	if (isatty(STDIN_FILENO))
	{
		if (lp->pipe_flag)
		{
			if (dup2(lp->pipe_prev_stdin_fd, STDIN_FILENO) == ERR)
				sh_fatal_err(DUP2_FAILED);
			// close(lp->pipe_prev_stdin_fd);
		}
		else
		{
			if (dup2(pipe_fd[STDIN_FILENO], STDIN_FILENO) == ERR)
				sh_fatal_err(DUP2_FAILED);
		}
		if ((lp->pipe_prev_stdin_fd = dup(pipe_fd[STDIN_FILENO])) == ERR)
			sh_fatal_err(DUP_FAILED);
		lp->pipe_flag = true;
	}
	else
	{
		close(pipe_fd[STDIN_FILENO]);
		lp->pipe_flag = false;
	}
}

static void	lp_pipe_logic_out(t_line_parser *lp, int32_t pipe_fd[2])
{
	if (isatty(STDOUT_FILENO))
	{
		if (dup2(pipe_fd[STDOUT_FILENO], STDOUT_FILENO) == ERR)
			sh_fatal_err(DUP2_FAILED);
	}
	else
		close(pipe_fd[STDOUT_FILENO]);
}

// static void	lp_pipe_logic(t_line_parser *lp, int32_t in, int32_t out)
// {
// 	int32_t		pipe_fd[2];

// 	if (pipe(pipe_fd) == ERR)
// 		sh_fatal_err(PIPE_FAILED);
// 	lp_pipe_logic_in(lp, in, pipe_fd);
// 	lp_pipe_logic_out(lp, out, pipe_fd);
// }

void		lp_pipe(t_line_parser *lp)
{
	// if (lp->pipe_flag)
	// 	lp_pipe_logic(lp, lp->pipe_prev_stdin_fd, STDOUT_FILENO);
	// else
	// 	lp_pipe_logic(lp, STDIN_FILENO, STDOUT_FILENO);
	int32_t		pipe_fd[2];

	if (pipe(pipe_fd) == ERR)
		sh_fatal_err(PIPE_FAILED);
	lp_pipe_logic_in(lp, pipe_fd);
	lp_pipe_logic_out(lp, pipe_fd);
	lp_push_command(lp);
	++lp->i;
}
