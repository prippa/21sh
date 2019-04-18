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

static void	lp_redirect_out_open_file(t_redirect *rdr)
{
	int32_t	file_desc;

	if (rdr->append_flag)
		file_desc = open(rdr->word, OPEN_APPEND_FLAGS, OPEN_CREATE_RW_RIGHTS);
	else
		file_desc = open(rdr->word, OPEN_REWRITE_FLAGS, OPEN_CREATE_RW_RIGHTS);
	if (file_desc == ERR)
		sh_fatal_err(OPEN_ERR);
	dup2(file_desc, rdr->fd);
}

static void	lp_redirect_out_init_flags(t_line_parser *lp, t_redirect *rdr)
{
	if (lp->line[++lp->i] == REDIRECT_OUT_C)
		rdr->append_flag = true;
	else if (lp->line[lp->i] == FDA_C)
		rdr->desc_flag = true;
	else
		--lp->i;
	++lp->i;
}

void		lp_redirect_out(t_line_parser *lp)
{
	t_redirect rdr;

	lp_init_rdr(&rdr, lp);
	lp_redirect_out_init_flags(lp, &rdr);
	rdr.word = sh_get_word(&lp->i, lp->line);
	if (lp_rdr_valid_word(rdr.word))
		lp_redirect_out_open_file(&rdr);
	ft_strdel(&rdr.word);
}
