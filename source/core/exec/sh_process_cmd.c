/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:32 by prippa            #+#    #+#             */
/*   Updated: 2019/05/01 10:31:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "info.h"
#include "builtin_static_box.h"
#include "environ_manipulation.h"

#define SH_CMD_NOT_FOUND	"%s: command not found"

static t_bool		sh_exec_by_bin_env_path(t_build *b)
{
	char	*path_value;
	char	**paths;
	size_t	i;

	if ((path_value = env_get_vlu_by_key(b->env->start, PATH_ENV)))
	{
		paths = ft_strsplit(path_value, PATH_ENV_SEPARATOR);
		i = -1;
		while (paths[++i])
			if (sh_check_path(paths[i], ft_strlen(paths[i]), b))
			{
				ft_arrdel(&paths);
				return (true);
			}
		ft_arrdel(&paths);
	}
	return (false);
}

static t_bool		sh_exec_by_bin(t_build *b)
{
	t_ht_elem *bin;

	if (sh()->env_exec_flag && env_get_vlu_by_key(b->env->start, PATH_ENV))
		return (sh_exec_by_bin_env_path(b));
	bin = HT_GET(&sh()->bin_path, *b->args, ft_strlen(*b->args));
	if (bin)
		return (sh_check_path(bin->value, bin->value_size, b));
	return (false);
}

static t_bool		sh_exec_by_full_path(t_build *b, const char *cmd_prefix)
{
	char	*value;
	t_bool	ups;

	ups = (ft_strchr(*b->args, UNIX_PATH_SEPARATOR) ? true : false);
	value = env_get_vlu_by_key(b->env->start, PATH_ENV);
	if ((!ups && value && ft_strcmp(value, EMPTY_STR)) ||
		(!ups && !value && sh()->env_exec_flag))
		return (false);
	if (!sh_path_access(*b->args, cmd_prefix))
		sh_exec(*b->args, b);
	return (true);
}

static t_bool		sh_exec_by_builtin(t_build *b)
{
	size_t	i;

	i = -1;
	while (++i < SH_BUILTIN_SIZE)
		if (!ft_strcmp(*b->args, g_builtin_box[i].s))
		{
			++b->args;
			g_builtin_box[i].f(b);
			return (true);
		}
	return (false);
}

void				sh_process_cmd(t_build *b, const char *cmd_prefix)
{
	if (sh_is_dir(*b->args))
	{
		ft_putstr_fd(cmd_prefix, STDERR_FILENO);
		sh_print_err(EXIT_FAILURE, MSG(IS_A_DIR, *b->args));
	}
	else
	{
		ft_to_str_lower(b->args);
		if (!sh_exec_by_builtin(b) &&
			!sh_exec_by_full_path(b, cmd_prefix) &&
			!sh_exec_by_bin(b))
		{
			ft_putstr_fd(cmd_prefix, STDERR_FILENO);
			sh_print_err(EXIT_FAILURE, MSG(SH_CMD_NOT_FOUND, *b->args));
		}
	}
}
