/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:51 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtin.h"
#include "environ_manipulation.h"
#include "messages.h"

#define ENV_I_F				"-i"
#define ENV_PREFIX			ENV_CMD ": "
#define ENV_INVALID_ARG		ENV_PREFIX "setenv %s: Invalid argument"

static t_bool	sh_env_check_kv(t_bool i_flag, t_build *nb, t_build *b)
{
	if (!i_flag)
		env_make_clone(nb->env, b->env->start);
	while (*b->args)
	{
		if (**b->args == KEY_VALUE_SEPARATOR)
		{
			sh_print_err(EXIT_FAILURE, MSG(ENV_INVALID_ARG, *b->args));
			return (false);
		}
		if (ft_strchr(*b->args, KEY_VALUE_SEPARATOR))
			sh_setenv_one_env(nb->env, *b->args, false);
		else
			break ;
		++b->args;
	}
	return (true);
}

static t_bool	sh_env_check_flag(char ***args)
{
	t_bool f;

	f = false;
	while (**args)
	{
		if (!ft_strcmp(ENV_I_F, **args))
			f = true;
		else
			break ;
		++(*args);
	}
	return (f);
}

void			sh_env(t_build *b)
{
	t_build	nb;
	t_list	env_list;

	LST_INIT(&env_list, &env_del_list);
	nb.env = &env_list;
	sh()->env_exec_flag = true;
	if (sh_env_check_kv(sh_env_check_flag(&b->args), &nb, b))
	{
		if (*b->args)
		{
			nb.args = b->args;
			sh_process_cmd(&nb, ENV_PREFIX);
		}
		else
			env_print(nb.env);
	}
	LST_DEL(nb.env);
	sh()->env_exec_flag = false;
}
