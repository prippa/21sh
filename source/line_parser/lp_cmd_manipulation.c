/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_cmd_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:53:14 by prippa            #+#    #+#             */
/*   Updated: 2019/04/24 11:53:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "builtin.h"
#include "info.h"
#include "environ_manipulation.h"

void	lp_del_commands_list(void *content, size_t content_size)
{
	t_command *cmd;

	(void)content_size;
	cmd = (t_command *)content;
	LST_DEL(&cmd->args_list);
	LST_DEL(&cmd->fd_list);
	ft_strdel(&cmd->error);
	ft_memdel(&content);
}

void	lp_init_command(t_command *cmd)
{
	ft_bzero(cmd, sizeof(t_command));
	LST_INIT(&cmd->args_list, &ft_cnt_delptr);
	LST_INIT(&cmd->fd_list, &ft_cnt_delptr);
}

void	lp_add_cmd(t_line_parser *lp)
{
	lp_add_arg(&lp->cmd);
	LST_PUSH_BACK(&lp->cmds, &lp->cmd, sizeof(t_command));
	lp_init_command(&lp->cmd);
}

char	**lp_get_command(t_command *cmd)
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

void	lp_run_command(char **args)
{
	t_build	b;

	b.env = &sh()->env;
	b.args = args;
	env_set(b.env, ENV(LAST_ARG_ENV, b.args[ft_arrlen(b.args) - 1]), true);
	sh_process_cmd(&b, SHELL_NAME ": ");
}
