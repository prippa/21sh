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

t_bool		lp_is_not_global_fd(int32_t fd, int32_t global_fd[3])
{
	if (fd != global_fd[0] && fd != global_fd[1] && fd != global_fd[2])
		return (true);
	return (false);
}

t_bool		lp_rdr_valid_word(const char *word)
{

	return (sh()->ok);
}

t_redirect	lp_init_rdr(t_redirect *rdr, t_line_parser *lp)
{
	ft_bzero(rdr, sizeof(t_redirect));
	rdr->fd = lp_rdr_get_file_desc(lp);
	if (!isatty(rdr->fd) && lp_is_not_global_fd(rdr->fd, sh()->fd))
		rdr->fd = STDOUT_FILENO;
}
