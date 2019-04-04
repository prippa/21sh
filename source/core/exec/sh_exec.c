/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:52:50 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:52:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "environ_manipulation.h"
#include "builtin.h"
#include <sys/wait.h>

static void		sh_do_magic(const char *path, char **args, char **env)
{
	pid_t	father;

	sh_init_sig_incase();
	if ((father = fork()) == ERR)
		sh_fatal_err(FORK_FAILED);
	if (father)
	{
		if (wait(&sh()->exec_code) == ERR)
			sh_fatal_err(WAIT_FAILED);
		if (WIFEXITED(sh()->exec_code) && sh()->exec_code)
		{
			sh()->exec_code = WEXITSTATUS(sh()->exec_code);
			sh()->ok = false;
		}
	}
	if (!father)
	{
		sh_init_sig_default();
		execve(path, args, env);
		exit(EXIT_FAILURE);
	}
	sh_init_sig_base();
}

void			sh_exec(const char *path, t_build *b)
{
	char		**env;

	if (access(path, X_OK) == ERR)
	{
		PRINT_ERR(EXIT_FAILURE, SH_PERM_DENIED, path);
		return ;
	}
	env = env_convert_to_arr(b->env->start, b->env->list_size);
	sh_do_magic(path, b->args, env);
	ft_arrdel(&env);
}
