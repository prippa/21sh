/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_static_box.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:20:15 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 20:20:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_STATIC_BOX_H
# define BUILTIN_STATIC_BOX_H

# include "builtin.h"

typedef void		(*t_builtin_func)(t_build *b);
typedef struct		s_builtin_box
{
	t_builtin_func	f;
	char			*s;
}					t_builtin_box;

static const t_builtin_box	g_builtin_box[SH_BUILTIN_SIZE] =
{
	{sh_cd, CD_CMD},
	{sh_echo, ECHO_CMD},
	{sh_env, ENV_CMD},
	{sh_setenv, SETENV_CMD},
	{sh_unsetenv, UNSETENV_CMD},
	{sh_exit, EXIT_CMD},
};

#endif
