/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:56:23 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:56:24 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

void	lp_add_arg(t_command *cmd)
{
	if (cmd->arg_buf_len)
		lp_join_to_arg(cmd, cmd->arg_buf, cmd->arg_buf_len);
	if (cmd->arg_len)
	{
		LST_PUSH_BACK_REF(&cmd->args_list, cmd->arg, cmd->arg_len);
		cmd->arg = NULL;
		*cmd->arg_buf = 0;
		cmd->arg_len = 0;
		cmd->arg_buf_len = 0;
	}
}

void	lp_space(t_line_parser *lp)
{
	lp_add_arg(&lp->cmd);
	++lp->i;
}
