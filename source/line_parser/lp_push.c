/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:57:09 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:57:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "builtin.h"
#include "messages.h"
#include "environ_manipulation.h"

static char	**lp_get_command(t_line_parser *lp)
{
	size_t		i;
	char		**args;
	t_list_elem	*start;

	args = (char **)ft_memalloc(sizeof(char *) * (lp->args_list.list_size + 1));
	start = lp->args_list.start;
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

void		lp_push_command(t_line_parser *lp)
{
	char	**args;

	lp_push_arg(lp);
	if (!lp->args_list.start)
		return ;
	if (sh()->ok)
	{
		args = lp_get_command(lp);
		lp_run_command(args);
		free(args);
		lp_reset_fd(sh()->fd);
	}
	LST_DEL(&lp->args_list);
}

void		lp_push_arg(t_line_parser *lp)
{
	if (lp->arg_buf_len)
		lp_join_to_arg(lp, lp->arg_buf, lp->arg_buf_len);
	if (lp->arg_len)
	{
		LST_PUSH_BACK_REF(&lp->args_list, lp->arg, lp->arg_len);
		lp->arg = NULL;
		*lp->arg_buf = 0;
		lp->arg_len = 0;
		lp->arg_buf_len = 0;
	}
}
