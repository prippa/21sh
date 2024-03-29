/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_rdr_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:16:41 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:16:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"
#include "info.h"

#define BAD_REDIR SHELL_NAME ": %s: ambiguous redirect"

void			lp_init_rdr(t_redirect *rdr, t_line_parser *lp, int32_t base_fd)
{
	intmax_t	n;
	uint16_t	n_len;
	char		*n_str;

	ft_bzero(rdr, sizeof(t_redirect));
	if (!ft_isdigit(lp->line[lp->i]))
		rdr->fd = base_fd;
	else
	{
		n = ft_atoi_max(&lp->line[lp->i]);
		n_len = ft_nbrlen(n);
		if (!lp->cmd.error && (n_len > ft_nbrlen(INT32_MAX) || n > INT32_MAX))
		{
			n_str = ft_strsub(&lp->line[lp->i], 0, n_len);
			lp->cmd.error = MSG(BAD_DESC, n_str);
			ft_strdel(&n_str);
		}
		lp->i += n_len;
		rdr->fd = (int32_t)n;
	}
}

static t_bool	lp_rdr_check_path(char **error_str, const char *word)
{
	char	*dir;

	if ((dir = ft_strrchr(word, UNIX_PATH_SEPARATOR)))
	{
		dir = ft_strsub(word, 0, dir - word + 1);
		if (access(dir, F_OK))
			*error_str = MSG(SHELL_NAME ": " NO_FILE_OR_DIR, word);
		else if (access(dir, R_OK))
			*error_str = MSG(SHELL_NAME ": " PERM_DENIED, word);
		ft_strdel(&dir);
	}
	return (*error_str ? true : false);
}

t_bool			lp_rdr_check_word_permission(const char *word,
					int32_t file_perm, t_command *cmd)
{
	if (cmd->error)
		return (true);
	else if (ft_strequ(word, EMPTY_STR))
		cmd->error = MSG(SHELL_NAME ": " NO_FILE_OR_DIR, word);
	else if (lp_rdr_check_path(&cmd->error, word))
		return (true);
	else if (!access(word, F_OK) && access(word, file_perm))
		cmd->error = MSG(SHELL_NAME ": " PERM_DENIED, word);
	return (cmd->error ? true : false);
}

void			lp_rdr_redirect_desc(t_redirect *rdr, t_command *cmd)
{
	intmax_t	n;

	if (ft_strequ(rdr->word, CLOSE_FD))
		LST_PUSH_BACK(&cmd->fd_list, (FD(-1, rdr->fd)), sizeof(t_dup2_fd));
	else if (!ft_is_str_digit(rdr->word))
		cmd->error = MSG(BAD_REDIR, rdr->word);
	else
	{
		n = ft_atoi_max(rdr->word);
		if (ft_nbrlen(n) > ft_nbrlen(INT32_MAX) || n > INT32_MAX)
			cmd->error = MSG(BAD_DESC, rdr->word);
		else
			LST_PUSH_BACK(&cmd->fd_list, (FD(n, rdr->fd)), sizeof(t_dup2_fd));
	}
}

void			lp_rdr_init_flags(t_line_parser *lp, t_redirect *rdr, char c)
{
	if (lp->line[++lp->i] == c)
		rdr->mod_flag = true;
	else if (lp->line[lp->i] == FDA_C)
		rdr->fda_flag = true;
	else
		--lp->i;
	++lp->i;
}
