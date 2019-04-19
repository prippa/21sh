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

#define BAD_DESC	SHELL_NAME ": %zd: Bad file descriptor"

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
		rdr->fda_flag = true;
	else
		--lp->i;
	++lp->i;
}

static void	lp_redirect_out_redir_desc(t_redirect *rdr)
{
	intmax_t	n;

	if (ft_strequ(rdr->word, CLOSE_FD))
		close(rdr->fd);
	else if (!ft_is_str_digit(rdr->word))
		lp_redirect_out_open_file(rdr);
	else
	{
		n = ft_atoi_max(rdr->word);
		if (n > STDERR_FILENO || n < STDIN_FILENO)
		{
			PRINT_ERR(EXIT_FAILURE, BAD_DESC, n);
		}
		else
			dup2(n, rdr->fd);
	}
}

void		lp_redirect_out(t_line_parser *lp)
{
	t_redirect rdr;

	lp_init_rdr(&rdr, lp);
	lp_redirect_out_init_flags(lp, &rdr);
	rdr.word = sh_get_word(&lp->i, lp->line);
	if (lp_rdr_valid_word(rdr.word, rdr.fda_flag))
	{
		if (rdr.fda_flag)
			lp_redirect_out_redir_desc(&rdr);
		else
			lp_redirect_out_open_file(&rdr);
	}
	ft_strdel(&rdr.word);
}
