/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_semicolon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:47 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:55:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "info.h"
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
			cmd->error = MSG(BAD_DESC_N, fd->fildes2);
		else if (fd->fildes == ERR)
			close(fd->fildes2);
		else if (!lp_is_valid_fd(fd->fildes) ||
			dup2(fd->fildes, fd->fildes2) == ERR)
			cmd->error = MSG(BAD_DESC_N, fd->fildes);
		if (cmd->error)
			return ;
		start = start->next;
	}
}

static void	lp_exec_command(t_command *cmd)
{
	char		**args;

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

static void	lp_init_pipe(t_bool next)
{
	int32_t	p[2];

	if (dup2(TERM_PIPE, STDIN_FILENO) == ERR)
		g_fef(DUP2_FAILED);
	if (pipe(p) == ERR)
		g_fef(PIPE_FAILED);
	if (next)
	{
		if (dup2(p[STDIN_FILENO], TERM_PIPE) == ERR)
			g_fef(DUP2_FAILED);
		if (dup2(p[STDOUT_FILENO], STDOUT_FILENO) == ERR)
			g_fef(DUP2_FAILED);
	}
	else
		close(TERM_PIPE);
	close(p[STDIN_FILENO]);
	close(p[STDOUT_FILENO]);
}

static void	lp_wait(void)
{
	while (sh()->childs_count--)
	{
		if (wait(&sh()->exec_code) == ERR)
			g_fef(WAIT_FAILED);
		if (WIFEXITED(sh()->exec_code) && sh()->exec_code)
		{
			sh()->exec_code = WEXITSTATUS(sh()->exec_code);
			sh()->ok = false;
		}
	}
	sh()->childs_count = 0;
}

void		lp_semicolon(t_line_parser *lp)
{
	t_list_elem	*start;

	lp_add_cmd(lp);
	start = lp->cmds.start;
	if (dup2(STDIN_FILENO, TERM_PIPE) == ERR)
		g_fef(PIPE_FAILED);
	while (start)
	{
		lp_init_pipe(start->next ? true : false);
		lp_exec_command(start->content);
		lp_reset_fd();
		start = start->next;
	}
	lp_wait();
	LST_DEL(&lp->cmds);
	++lp->i;
}
