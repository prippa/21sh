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
#include "builtin.h"
#include "environ_manipulation.h"

static char	**lp_get_command(t_command *cmd)
{
	size_t		i;
	char		**args;
	t_list_elem	*start;

	args = (char **)ft_memalloc(
		sizeof(char *) * (cmd->args_list.list_size + 1));
	start = cmd->args_list.start;
	i = -1;
	while (start)
	{
		args[++i] = (char *)start->content;
		start = start->next;
	}
	return (args);
}

static void	lp_run_command(char **args)
{
	t_build	b;

	b.env = &sh()->env;
	b.args = args;
	env_set(b.env, ENV(PREV_CMD_ENV, *b.args), true);
	sh_process_cmd(&b, SHELL_NAME ": ");
}

static void	lp_set_fd(int32_t fd[3])
{
	int8_t	i;

	i = STDIN_FILENO;
	while (i <= STDERR_FILENO)
	{
		if (fd[i] == ERR)
			close(i);
		else
			dup2(fd[i], i);
		++i;
	}
}

void		lp_exec_command(t_command *cmd)
{
	char		**args;

	if (!cmd->args_list.list_size || !cmd->cbe)
		return ;
	lp_set_fd(cmd->fd);
	args = lp_get_command(cmd);
	lp_run_command(args);
	free(args);
}

void		lp_semicolon(t_line_parser *lp)
{
	int32_t		reset_fd[3];
	t_list_elem	*start;

	lp_add_cmd(lp);
	reset_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	reset_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	reset_fd[STDERR_FILENO] = dup(STDERR_FILENO);
	if (reset_fd[STDIN_FILENO] == ERR || reset_fd[STDOUT_FILENO] == ERR ||
		reset_fd[STDERR_FILENO] == ERR)
		sh_fatal_err(DUP_FAILED);
	start = lp->cmds.start;
	while (start)
	{
		lp_exec_command(start->content);
		lp_reset_fd(reset_fd);
		start = start->next;
	}
	close(reset_fd[STDIN_FILENO]);
	close(reset_fd[STDOUT_FILENO]);
	close(reset_fd[STDERR_FILENO]);
	LST_DEL(&lp->cmds);
	++lp->i;
}
