/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_arg_buf_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:47:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:47:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

static void	lp_double_join(t_command *cmd, const char *src, size_t len)
{
	char *buf_plus_s;

	if (cmd->arg_buf_len)
		buf_plus_s = ft_strnjoin(cmd->arg_buf, src, cmd->arg_buf_len, len);
	else
		buf_plus_s = (char *)src;
	lp_join_to_arg(cmd, buf_plus_s, cmd->arg_buf_len + len);
	if (cmd->arg_buf_len)
		ft_strdel(&buf_plus_s);
	cmd->arg_buf_len = 0;
	*cmd->arg_buf = 0;
}

static void	lp_join_cpy(t_command *cmd, const char *src, size_t len)
{
	lp_join_to_arg(cmd, cmd->arg_buf, cmd->arg_buf_len);
	ft_strncpy(cmd->arg_buf, src, len);
	cmd->arg_buf_len = len;
	cmd->arg_buf[cmd->arg_buf_len] = 0;
}

void		lp_join_to_arg(t_command *cmd, const char *src, size_t len)
{
	if (!len)
		return ;
	if (cmd->arg)
		ft_strjoin_free(&cmd->arg, src, cmd->arg_len, len);
	else
		cmd->arg = ft_strsub(src, 0, len);
	cmd->arg_len += len;
}

void		lp_write_to_arg_buf_char(t_command *cmd, char c)
{
	if (cmd->arg_buf_len + 1 > ARG_BUF_SIZE)
		lp_join_cpy(cmd, &c, 1);
	else
	{
		cmd->arg_buf[cmd->arg_buf_len] = c;
		++cmd->arg_buf_len;
	}
}

void		lp_write_to_arg_buf_str(t_command *cmd,
				const char *src, size_t len)
{
	if (len > ARG_BUF_SIZE)
		lp_double_join(cmd, src, len);
	else if (cmd->arg_buf_len + len > ARG_BUF_SIZE)
		lp_join_cpy(cmd, src, len);
	else
	{
		ft_strncpy(cmd->arg_buf + cmd->arg_buf_len, src, len);
		cmd->arg_buf_len += len;
		cmd->arg_buf[cmd->arg_buf_len] = 0;
	}
}
