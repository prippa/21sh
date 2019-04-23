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

static void	lp_set_fd(int32_t reset_fd[3], t_list *fd_list)
{
	t_list_elem	*start;
	t_dup2_fd	*fd;

	start = fd_list->start;
	while (start)
	{
		fd = (t_dup2_fd *)start->content;
		if (lp_is_valid_fd(reset_fd, fd->fildes2))
		{
			if (fd->fildes == ERR)
				close(fd->fildes2);
			else if (dup2(fd->fildes, fd->fildes2) == ERR)
			{
				sh_print_err(EXIT_FAILURE, MSG(BAD_DESC_N, fd->fildes));
				return ;
			}
		}
		start = start->next;
	}
}

static void	lp_exec_command(int32_t reset_fd[3], t_command *cmd)
{
	char		**args;

	lp_set_fd(reset_fd, &cmd->fd_list);
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
	lp_close_fd_list(reset_fd, &cmd->fd_list);
}

static void	lp_semicolon_loop(int32_t reset_fd[3], t_line_parser *lp)
{
	t_list_elem	*start;
	int32_t		fd_in;
	int32_t		p[2];

	start = lp->cmds.start;
	fd_in = STDIN_FILENO;
	while (start)
	{
		if (dup2(fd_in, STDIN_FILENO) == ERR)
			sh_fatal_err(DUP2_FAILED);
		if (pipe(p) == ERR)
			sh_fatal_err(PIPE_FAILED);
		if (start->next)
		{
			if (dup2(p[STDOUT_FILENO], STDOUT_FILENO) == ERR)
				sh_fatal_err(DUP2_FAILED);
			close(p[STDOUT_FILENO]);
		}
		lp_exec_command(reset_fd, start->content);
		lp_reset_fd(reset_fd);
		fd_in = p[STDIN_FILENO];
		start = start->next;
	}
}

void		lp_semicolon(t_line_parser *lp)
{
	int32_t		reset_fd[3];

	lp_add_cmd(lp);
	lp_clone_std_fd(reset_fd);
	lp_semicolon_loop(reset_fd, lp);
	lp_close_fd(reset_fd);
	LST_DEL(&lp->cmds);
	++lp->i;
}
