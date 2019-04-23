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

void	lp_clone_std_fd(int32_t clone_fd[3])
{
	clone_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	clone_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	clone_fd[STDERR_FILENO] = dup(STDERR_FILENO);
	if (clone_fd[STDIN_FILENO] == ERR || clone_fd[STDOUT_FILENO] == ERR ||
		clone_fd[STDERR_FILENO] == ERR)
		sh_fatal_err(DUP_FAILED);
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

void	lp_close_fd(int32_t fd[3])
{
	close(fd[STDIN_FILENO]);
	close(fd[STDOUT_FILENO]);
	close(fd[STDERR_FILENO]);
}

t_bool	lp_is_valid_fd(int32_t fds[3], int32_t fd)
{
	if (fd == fds[STDIN_FILENO] || fd == fds[STDOUT_FILENO] ||
		fd == fds[STDERR_FILENO])
		return (false);
	return (true);
}
