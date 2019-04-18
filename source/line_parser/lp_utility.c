#include "line_parser.h"
#include "messages.h"

void		lp_reset_fd(int32_t fd[3])
{
	if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(fd[STDOUT_FILENO], STDOUT_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(fd[STDERR_FILENO], STDERR_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
}
