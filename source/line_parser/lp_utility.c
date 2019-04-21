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
	cmd->cbe = true;
}

void		lp_reset_fd(int32_t	fd[3])
{
	if (dup2(fd[STDIN_FILENO], STDIN_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(fd[STDOUT_FILENO], STDOUT_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
	if (dup2(fd[STDERR_FILENO], STDERR_FILENO) == ERR)
		sh_fatal_err(DUP2_FAILED);
}

void		lp_add_cmd(t_line_parser *lp)
{
	lp_add_arg(&lp->cmd);
	lp->cmd.fd[STDIN_FILENO] = dup(STDIN_FILENO);
	lp->cmd.fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	lp->cmd.fd[STDERR_FILENO] = dup(STDERR_FILENO);
	LST_PUSH_BACK(&lp->cmds, &lp->cmd, sizeof(t_command));
	lp_init_commnd(&lp->cmd);
	lp_reset_fd(sh()->fd);
}

void		lp_add_arg(t_command *cmd)
{
	if (cmd->arg_buf_len)
		lp_join_to_arg(cmd, cmd->arg_buf, cmd->arg_buf_len);
	if (cmd->arg_len)
	{
		LST_PUSH_BACK_REF(&cmd->args_list, cmd->arg, cmd->arg_len);
		cmd->arg = NULL;
		*cmd->arg_buf = 0;
		cmd->arg_len = 0;
		cmd->arg_buf_len = 0;
	}
}
