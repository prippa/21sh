/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:52:50 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:52:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "info.h"
#include "environ_manipulation.h"
#include "builtin.h"

static void	sh_close_backup_descriptors(void)
{
	close(TERM_STDIN);
	close(TERM_STDOUT);
	close(TERM_STDERR);
	close(TERM_PIPE);
}

static void	sh_do_magic(const char *path, char **args, char **env)
{
	pid_t	father;

	if ((father = fork()) == ERR)
		g_fef(FORK_FAILED);
	if (!father)
	{
		sh_reset_signals();
		sh_close_backup_descriptors();
		execve(path, args, env);
		exit(EXIT_FAILURE);
	}
	++sh()->childs_count;
}

void		sh_exec(const char *path, t_build *b)
{
	char		**env;

	if (access(path, X_OK) == ERR)
	{
		sh_print_err(EXIT_FAILURE, MSG(SH_PERM_DENIED, path));
		return ;
	}
	env = env_convert_to_arr(b->env->start, b->env->list_size);
	sh_do_magic(path, b->args, env);
	ft_arrdel(&env);
}
