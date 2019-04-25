/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:36:02 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:36:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtin.h"
#include "environ_manipulation.h"
#include "info.h"

#define SH_UNSETENV_USG	SHELL_NAME ": " "unsetenv: usage: unsetenv [key] ..."
#define SH_UNSETENV_NO_NAME	SHELL_NAME ": " "unsetenv: '%s' not found"

void	sh_unsetenv(t_build *b)
{
	if (!*b->args)
	{
		sh_print_err(EXIT_FAILURE, MSG(SH_UNSETENV_USG, NULL));
		return ;
	}
	while (*b->args)
	{
		if (env_unset(b->env, *b->args))
			sh_print_err(EXIT_FAILURE, MSG(SH_UNSETENV_NO_NAME, *b->args));
		++b->args;
	}
}
