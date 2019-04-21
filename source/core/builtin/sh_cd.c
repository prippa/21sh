/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:35:41 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:35:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "builtin.h"
#include "environ_manipulation.h"

#define CD_DASH_F			"-"
#define CD					SHELL_NAME ": " CD_CMD ": "
#define CD_TO_MANY_ARGS		CD TO_MANY_ARGS
#define CD_NOT_DIR			CD "'%s': Not a directory"
#define CD_PERM_DENIED		CD PERM_DENIED
#define CD_FILENAME_TO_LONG	CD "'%s': File name too long"
#define CD_NO_ENV			CD "%s not set"
#define CD_L_F				"-L"
#define CD_P_F				"-P"

static t_bool	sh_cd_path_valid(const char *path)
{
	if (sh_is_valid_path(path))
		sh_print_err(EXIT_FAILURE, MSG(CD_FILENAME_TO_LONG, path));
	else if (sh_path_access(path, CD))
		return (sh()->ok);
	else if (!sh_is_dir(path))
		sh_print_err(EXIT_FAILURE, MSG(CD_NOT_DIR, path));
	else if (access(path, X_OK) == ERR)
		sh_print_err(EXIT_FAILURE, MSG(CD_PERM_DENIED, path));
	return (sh()->ok);
}

static void		sh_cd_make_move(t_list *env_list, const char *path, t_bool slf)
{
	char *pwd;

	if (sh()->env_exec_flag)
		return ;
	if ((pwd = env_get_vlu_by_key(env_list->start, PWD_ENV)))
		env_set(env_list, ENV(OLDPWD_ENV, pwd), true);
	else if (env_get_vlu_by_key(env_list->start, OLDPWD_ENV))
		env_unset(env_list, OLDPWD_ENV);
	if (chdir(path) == ERR)
		sh_fatal_err(CHDIR_FAILED);
	if (!slf)
	{
		pwd = sh()->pwd;
		sh()->pwd = sh_join_path_to_pwd(pwd, path);
		ft_strdel(&pwd);
		pwd = ft_strdup(sh()->pwd);
	}
	else
	{
		if (!(pwd = getcwd(NULL, 0)))
			sh_fatal_err(GETCWD_FAILED);
		ft_strdup_free(&sh()->pwd, pwd);
	}
	env_set(env_list, ENV(PWD_ENV, pwd), true);
	ft_strdel(&pwd);
}

static t_bool	sh_cd_by_env(t_list *env_list, const char *env_key, t_bool slf)
{
	char *path;

	if (!(path = env_get_vlu_by_key(env_list->start, env_key)))
	{
		sh_print_err(EXIT_FAILURE, MSG(CD_NO_ENV, env_key));
		return (false);
	}
	if (!sh_cd_path_valid(path))
		return (false);
	path = ft_strdup(path);
	sh_cd_make_move(env_list, path, slf);
	ft_strdel(&path);
	return (true);
}

static t_bool	sh_cd_check_flags(char ***args)
{
	t_bool f;

	f = false;
	while (**args)
	{
		if (!ft_strcmp(CD_L_F, **args))
			f = false;
		else if (!ft_strcmp(CD_P_F, **args))
			f = true;
		else
			break ;
		++(*args);
	}
	return (f);
}

void			sh_cd(t_build *b)
{
	t_bool	symb_link_flag;

	symb_link_flag = sh_cd_check_flags(&b->args);
	if (!*b->args)
		sh_cd_by_env(b->env, HOME_ENV, symb_link_flag);
	else if (*(b->args + 1))
		sh_print_err(EXIT_FAILURE, MSG(CD_TO_MANY_ARGS, NULL));
	else if (!ft_strcmp(*b->args, CD_DASH_F))
	{
		if (sh_cd_by_env(b->env, OLDPWD_ENV, symb_link_flag))
			ft_putendl(env_get_vlu_by_key(b->env->start, PWD_ENV));
	}
	else if (sh_cd_path_valid(*b->args))
		sh_cd_make_move(b->env, *b->args, symb_link_flag);
	if (sh()->ok)
		sh_update_curent_dir_name();
}
