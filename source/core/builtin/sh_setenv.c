/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:56 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "info.h"
#include "builtin.h"
#include "environ_manipulation.h"

#define SH_SETENV_INV_ARG SHELL_NAME ": " "setenv: '%s' not a valid identifier"

static t_bool	sh_setenv_strictly_valid(const char *key)
{
	if (ft_isalpha_in_case(*key))
	{
		while (*(++key))
			if (!ft_isalnum_in_case(*key))
				return (true);
		return (false);
	}
	return (true);
}

int32_t			sh_setenv_one_env(t_list *env_list,
					const char *env, t_bool strictly_valid_flag)
{
	char	*i;
	t_bool	res;
	t_env	e;

	res = false;
	if (!(i = ft_strchr(env, KEY_VALUE_SEPARATOR)))
		return (ERR);
	e.key = ft_strsub(env, 0, i - env);
	e.value = ft_strdup(&env[(i - env) + 1]);
	if (strictly_valid_flag)
		res = sh_setenv_strictly_valid(e.key);
	if (!res)
		env_set(env_list, &e, true);
	env_del_body(&e);
	return (res);
}

void			sh_setenv(t_build *b)
{
	if (!*b->args)
	{
		env_print(b->env);
		return ;
	}
	while (*b->args)
	{
		if (sh_setenv_one_env(b->env, *b->args, true))
			sh_print_err(EXIT_FAILURE, MSG(SH_SETENV_INV_ARG, *b->args));
		++b->args;
	}
}
