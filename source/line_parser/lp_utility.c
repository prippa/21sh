#include "line_parser.h"
#include "messages.h"

void		lp_del_commands_list(void *content, size_t content_size)
{
	t_command *cmd;

	cmd = (t_command *)content;
	LST_DEL(&cmd->args_list);
	ft_memdel(&content);
}

void		lp_init_commnd(t_command *cmd)
{
	ft_bzero(cmd, sizeof(t_command));
	LST_INIT(&cmd->args_list, &ft_cnt_delptr);
	if ((cmd->fd[STDIN_FILENO] = dup(sh()->fd[STDIN_FILENO])) == ERR)
		sh_fatal_err(DUP_FAILED);
	if ((cmd->fd[STDOUT_FILENO] = dup(sh()->fd[STDOUT_FILENO])) == ERR)
		sh_fatal_err(DUP_FAILED);
	if ((cmd->fd[STDERR_FILENO] = dup(sh()->fd[STDERR_FILENO])) == ERR)
		sh_fatal_err(DUP_FAILED);
}
