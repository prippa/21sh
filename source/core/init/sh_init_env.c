/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:32:58 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 12:32:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin.h"
#include "environ_manipulation.h"

static void	sh_set_shell_lvl(t_build *b)
{
	char		*value;

	if ((value = env_get_vlu_by_key(b->env->start, SHELL_LVL_ENV)))
	{
		value = ft_itoa_max(ft_atoi_max(value) + 1);
		env_set(b->env, ENV(SHELL_LVL_ENV, value), true);
		ft_strdel(&value);
	}
	else
		env_set(b->env, ENV(SHELL_LVL_ENV, "1"), true);
}

static void	sh_set_pwd(t_build *b)
{
	if (!env_get_vlu_by_key(b->env->start, PWD_ENV))
		env_set(b->env, ENV(PWD_ENV, sh()->pwd), true);
}

static void	sh_set_path(t_build *b)
{
	if (!env_get_vlu_by_key(b->env->start, PATH_ENV))
		env_set(b->env, ENV(PATH_ENV, DEFAULT_BIN_PATH), true);
}

void		sh_init_env(void)
{
	extern char	**environ;
	t_build		b;

	LST_INIT(&sh()->env, &env_del_list);
	b.env = &sh()->env;
	b.args = environ;
	sh_setenv(&b);
	env_set(b.env, ENV(SHELL_ENV, SHELL_NAME), true);
	sh_set_pwd(&b);
	sh_set_shell_lvl(&b);
	sh_set_path(&b);
}
