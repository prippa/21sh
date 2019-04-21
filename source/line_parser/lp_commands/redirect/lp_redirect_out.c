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
#include "messages.h"

static void	lp_redirect_out_open_file(t_redirect *rdr)
{
	int32_t	file_desc;

	if (rdr->mod_flag)
		file_desc = open(rdr->word, OPEN_APPEND_FLAGS, OPEN_CREATE_RW_RIGHTS);
	else
		file_desc = open(rdr->word, OPEN_REWRITE_FLAGS, OPEN_CREATE_RW_RIGHTS);
	if (file_desc == ERR)
		sh_fatal_err(OPEN_ERR);
	dup2(file_desc, rdr->fd);
}

void		lp_redirect_out(t_line_parser *lp)
{
	t_redirect rdr;

	lp_init_rdr(&rdr, lp, STDOUT_FILENO);
	lp_rdr_init_flags(lp, &rdr, REDIRECT_OUT_C);
	rdr.word = sh_get_word(&lp->i, lp->line);
	lp->cmd.cbe = lp_rdr_valid_word(rdr.word, rdr.fda_flag, W_OK | R_OK);
	if (lp->cmd.cbe)
	{
		if (rdr.fda_flag)
			lp->cmd.cbe = lp_rdr_redirect_desc(&rdr);
		else
			lp_redirect_out_open_file(&rdr);
	}
	ft_strdel(&rdr.word);
}
