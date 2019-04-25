/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_redirect_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:07:34 by prippa            #+#    #+#             */
/*   Updated: 2019/04/17 14:07:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"
#include "info.h"

static void	lp_redirect_out_open_file(t_redirect *rdr, t_command *cmd)
{
	int32_t	file_desc;

	if (rdr->mod_flag)
		file_desc = open(rdr->word, OPEN_APPEND_FLAGS, OPEN_CREATE_RW_RIGHTS);
	else
		file_desc = open(rdr->word, OPEN_REWRITE_FLAGS, OPEN_CREATE_RW_RIGHTS);
	if (file_desc == ERR)
		g_fef(OPEN_ERR);
	LST_PUSH_BACK(&cmd->fd_list, (FD(file_desc, rdr->fd)), sizeof(t_dup2_fd));
}

void		lp_redirect_out(t_line_parser *lp)
{
	t_redirect rdr;

	lp_init_rdr(&rdr, lp, STDOUT_FILENO);
	lp_rdr_init_flags(lp, &rdr, REDIRECT_OUT_C);
	rdr.word = sh_get_word(&lp->i, lp->line);
	if (lp_rdr_check_word_permission(rdr.word, W_OK | R_OK, &lp->cmd) == OK)
	{
		if (rdr.fda_flag)
			lp_rdr_redirect_desc(&rdr, &lp->cmd);
		else
			lp_redirect_out_open_file(&rdr, &lp->cmd);
	}
	ft_strdel(&rdr.word);
}
