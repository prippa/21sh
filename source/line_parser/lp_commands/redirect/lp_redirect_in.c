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

static void	lp_rdr_heredoc(int32_t file_desc[2])
{
	if (pipe(file_desc) == ERR)
		sh_fatal_err(PIPE_FAILED);
	write(file_desc[STDOUT_FILENO],
		hd()->heredoc.start->content,
		hd()->heredoc.start->content_size);
	LST_POP_FRONT(&hd()->heredoc);
	close(file_desc[STDOUT_FILENO]);
}

static void	lp_rdr_base_redirect_in(t_redirect *rdr, int32_t file_desc[2],
				t_command *cmd)
{
	if (access(rdr->word, F_OK))
	{
		cmd->error = MSG(SHELL_NAME ": " NO_FILE_OR_DIR, rdr->word);
		return ;
	}
	if ((file_desc[STDIN_FILENO] = open(rdr->word, O_RDONLY)) == ERR)
		sh_fatal_err(OPEN_ERR);
}

static void	lp_redirect_in_open_file(t_redirect *rdr, t_command *cmd)
{
	int32_t	file_desc[2];

	if (rdr->mod_flag)
		lp_rdr_heredoc(file_desc);
	else
		lp_rdr_base_redirect_in(rdr, file_desc, cmd);
	if (!cmd->error)
		LST_PUSH_BACK(&cmd->fd_list,
			(FD(file_desc[STDIN_FILENO], rdr->fd)), sizeof(t_dup2_fd));
}

void		lp_redirect_in(t_line_parser *lp)
{
	t_redirect rdr;

	lp_init_rdr(&rdr, lp, STDIN_FILENO);
	lp_rdr_init_flags(lp, &rdr, REDIRECT_IN_C);
	rdr.word = sh_get_word(&lp->i, lp->line);
	if (lp_rdr_check_word_permision(rdr.word, W_OK | R_OK, &lp->cmd) == OK)
	{
		if (rdr.fda_flag)
			lp_rdr_redirect_desc(&rdr, &lp->cmd);
		else
			lp_redirect_in_open_file(&rdr, &lp->cmd);
	}
	ft_strdel(&rdr.word);
}
