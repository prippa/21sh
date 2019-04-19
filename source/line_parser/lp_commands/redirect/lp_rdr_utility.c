#include "line_parser.h"
#include "messages.h"

#define BAD_FILE_DESC SHELL_NAME ": %u: Bad file descriptor"
#define DESC_MAX	1023

int32_t		lp_rdr_get_file_desc(t_line_parser *lp)
{
	intmax_t	n;

	if (!ft_isdigit(lp->line[lp->i]))
		return (ERR);
	n = ft_atoi_max(&lp->line[lp->i]);
	lp->i += ft_nbrlen(n);
	if (n > DESC_MAX)
	{
		PRINT_ERR(EXIT_FAILURE, BAD_FILE_DESC, n);
		return (ERR);
	}
	return (n);
}

t_bool		lp_rdr_valid_word(const char *word, t_bool fda_flag)
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
			(!access(word, F_OK) && access(word, W_OK | R_OK)))
		{
			PRINT_ERR(EXIT_FAILURE, SHELL_NAME ": " PERM_DENIED, word);
		}
		ft_strdel(&dir);
	}
	return (sh()->ok);
}

void		lp_init_rdr(t_redirect *rdr, t_line_parser *lp)
{
	ft_bzero(rdr, sizeof(t_redirect));
	rdr->fd = lp_rdr_get_file_desc(lp);
	if (!isatty(rdr->fd) &&
		(rdr->fd != sh()->fd[0] &&
		rdr->fd != sh()->fd[1] &&
		rdr->fd != sh()->fd[2]))
		rdr->fd = STDOUT_FILENO;
}
