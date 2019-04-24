#include "line_parser.h"
#include "messages.h"

void	lp_reset_fd(int32_t	fd[3])
{
	if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(fd[STDOUT_FILENO], STDOUT_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(fd[STDERR_FILENO], STDERR_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
}

void	lp_close_fd_list(int32_t reset_fd[3], t_list *fd)
{
	t_list_elem *start;
	t_dup2_fd	*fds;

	start = fd->start;
	while (start)
	{
		fds = (t_dup2_fd *)start->content;
		if (lp_is_valid_fd(reset_fd, fds->fildes))
			close(fds->fildes);
		if (lp_is_valid_fd(reset_fd, fds->fildes2))
			close(fds->fildes2);
		start = start->next;
	}
}

t_bool	lp_is_valid_fd(int32_t fds[3], int32_t fd)
{
	if (fd == fds[STDIN_FILENO] || fd == fds[STDOUT_FILENO] ||
		fd == fds[STDERR_FILENO])
		return (false);
	return (true);
}
