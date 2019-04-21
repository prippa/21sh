/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_redirect_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:07:26 by prippa            #+#    #+#             */
/*   Updated: 2019/04/17 14:07:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"
#include "messages.h"
#include "heredoc.h"

static void	lp_rdr_heredoc(t_redirect *rdr, int32_t file_desc[2])
{
	if (pipe(file_desc) == ERR)
		sh_fatal_err(PIPE_FAILED);
	write(file_desc[STDOUT_FILENO],
		hd()->heredoc.start->content,
		hd()->heredoc.start->content_size);
	LST_POP_FRONT(&hd()->heredoc);
	close(file_desc[STDOUT_FILENO]);
}

static void	lp_rdr_base_redirect_in(t_redirect *rdr, int32_t file_desc[2])
{
	if (access(rdr->word, F_OK))
	{
		sh_print_err(EXIT_FAILURE, MSG(SHELL_NAME ": " NO_FILE_OR_DIR, rdr->word));
		return ;
	}
	if ((file_desc[STDIN_FILENO] = open(rdr->word, O_RDONLY)) == ERR)
		sh_fatal_err(OPEN_ERR);
}

static void	lp_redirect_in_open_file(t_redirect *rdr)
{
	int32_t	file_desc[2];

	if (rdr->mod_flag)
		lp_rdr_heredoc(rdr, file_desc);
	else
		lp_rdr_base_redirect_in(rdr, file_desc);
	if (rdr->fd != ERR)
	{
		if (dup2(file_desc[STDIN_FILENO], rdr->fd) == ERR)
			sh_fatal_err(DUP2_FAILED);
	}
	else
		close(file_desc[STDIN_FILENO]);
}

void		lp_redirect_in(t_line_parser *lp)
{
	t_redirect rdr;

	lp_init_rdr(&rdr, lp, STDIN_FILENO);
	lp_rdr_init_flags(lp, &rdr, REDIRECT_IN_C);
	rdr.word = sh_get_word(&lp->i, lp->line);
	if (lp_rdr_valid_word(rdr.word, rdr.fda_flag, R_OK))
	{
		if (rdr.fda_flag)
			lp_rdr_redirect_desc(&rdr);
		else
			lp_redirect_in_open_file(&rdr);
	}
	ft_strdel(&rdr.word);
}
