#include "line_parser.h"
#include "syntax_characters.h"
#include "messages.h"

#define BAD_DESC	SHELL_NAME ": %zd: Bad file descriptor"
#define DESC_MAX	1023

static int32_t	lp_rdr_get_file_desc(t_line_parser *lp)
{
	intmax_t	n;

	if (!ft_isdigit(lp->line[lp->i]))
		return (ERR);
	n = ft_atoi_max(&lp->line[lp->i]);
	lp->i += ft_nbrlen(n);
	if (n > DESC_MAX)
	{
		PRINT_ERR(EXIT_FAILURE, BAD_DESC, n);
		return (ERR);
	}
	return (n);
}

void			lp_init_rdr(t_redirect *rdr, t_line_parser *lp, int32_t base_fd)
{
	ft_bzero(rdr, sizeof(t_redirect));
	rdr->fd = lp_rdr_get_file_desc(lp);
	if (rdr->fd == ERR)
		rdr->fd = base_fd;
	else if (!isatty(rdr->fd) ||
		rdr->fd == sh()->fd[0] ||
		rdr->fd == sh()->fd[1] ||
		rdr->fd == sh()->fd[2])
		rdr->fd = ERR;
}

t_bool			lp_rdr_valid_word(const char *word, t_bool fda_flag, int32_t file_perm)
{
	char	*dir;

	if (ft_strequ(word, EMPTY_STR))
	{
		PRINT_ERR(EXIT_FAILURE, SHELL_NAME ": " NO_FILE_OR_DIR, word);
	}
	else if ((dir = ft_strrchr(word, UNIX_PATH_SEPARATOR)))
	{
		dir = ft_strsub(word, 0, dir - word);
		if (access(dir, F_OK))
		{
			PRINT_ERR(EXIT_FAILURE, SHELL_NAME ": " NO_FILE_OR_DIR, word);
		}
		else if (access(dir, W_OK | R_OK | X_OK) ||
			(!access(word, F_OK) && access(word, file_perm)))
		{
			PRINT_ERR(EXIT_FAILURE, SHELL_NAME ": " PERM_DENIED, word);
		}
		ft_strdel(&dir);
	}
	return (sh()->ok);
}

void			lp_rdr_redirect_desc(t_redirect *rdr)
{
	intmax_t	n;

	if (ft_strequ(rdr->word, CLOSE_FD))
		close(rdr->fd);
	else
	{
		n = ft_atoi_max(rdr->word);
		if (n > STDERR_FILENO || n < STDIN_FILENO)
		{
			PRINT_ERR(EXIT_FAILURE, BAD_DESC, n);
		}
		else
		{
			if (dup2(n, rdr->fd) == ERR)
				sh_fatal_err(DUP2_FAILED);
		}
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
