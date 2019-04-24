/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_semicolon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:47 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:55:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "messages.h"
#include <signal.h>
#include <sys/wait.h>

static void	lp_set_fd(t_command *cmd)
{
	t_list_elem	*start;
	t_dup2_fd	*fd;

	start = cmd->fd_list.start;
	while (start)
	{
		fd = (t_dup2_fd *)start->content;
		if (!lp_is_valid_fd(fd->fildes2))
		{
			cmd->error = MSG(BAD_DESC_N, fd->fildes2);
			return ;
		}
		if (fd->fildes == ERR)
			close(fd->fildes2);
		else if (!lp_is_valid_fd(fd->fildes) ||
			dup2(fd->fildes, fd->fildes2) == ERR)
		{
			cmd->error = MSG(BAD_DESC_N, fd->fildes);
			return ;
		}
		start = start->next;
	}
}

static void	lp_init_pipe(int32_t *fd_in, t_bool next)
{
	int32_t	p[2];

	if (dup2(*fd_in, STDIN_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (pipe(p) == ERR)
		sh_fatal_err(PIPE_FAILED);
	if (next)
	{
		if (dup2(p[STDOUT_FILENO], STDOUT_FILENO) == ERR)
			sh_fatal_err(DUP2_FAILED);
	}
	if (dup2(p[STDIN_FILENO], TERM_PIPE) == ERR)
		sh_fatal_err(DUP2_FAILED);
	close(p[STDIN_FILENO]);
	close(p[STDOUT_FILENO]);
	*fd_in = TERM_PIPE;
}

static void	lp_exec_command(t_command *cmd, int32_t *fd_in, t_bool next)
{
	char		**args;

	lp_init_pipe(fd_in, next);
	lp_set_fd(cmd);
	if (cmd->error)
	{
		sh_print_err(EXIT_FAILURE, cmd->error);
		cmd->error = NULL;
	}
	else if (cmd->args_list.list_size)
	{
		args = lp_get_command(cmd);
		lp_run_command(args);
		free(args);
	}
	lp_close_fd_list(&cmd->fd_list);
}

static void	lp_wait(t_list *pids)
{
	t_list_elem	*end;

	end = pids->end;
	while (end)
	{
		if (end->next)
			kill(*(pid_t *)end->content, SIGPIPE);
		else
		{
			if (waitpid(*(pid_t *)end->content, &sh()->exec_code, 0) == ERR)
				sh_fatal_err(WAIT_FAILED);
			if (WIFEXITED(sh()->exec_code) && sh()->exec_code)
			{
				sh()->exec_code = WEXITSTATUS(sh()->exec_code);
				sh()->ok = false;
			}
		}
		end = end->prev;
	}
}

void		lp_semicolon(t_line_parser *lp)
{
	t_list_elem	*start;
	int32_t		fd_in;

	lp_add_cmd(lp);
	start = lp->cmds.start;
	fd_in = STDIN_FILENO;
	while (start)
	{
		lp_exec_command(start->content, &fd_in, (start->next ? true : false));
		lp_reset_fd();
		start = start->next;
	}
	lp_wait(&sh()->pids);
	LST_DEL(&lp->cmds);
	LST_DEL(&sh()->pids);
	++lp->i;
}
