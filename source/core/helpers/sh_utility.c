/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 18:10:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "syntax_characters.h"
#include "environ_manipulation.h"
#include "builtin.h"

#define SH_ERR		"ERROR: " SHELL_NAME " : %s\n"

t_bool		sh_check_path(const char *path, size_t path_len, t_build *b)
{
	char	*full_path;
	int32_t	res;

	full_path = ft_strnew(path_len + ft_strlen(*b->args) + 1);
	ft_strncpy(full_path, path, path_len);
	ft_strcpy(full_path + path_len, (char[2]){ UNIX_PATH_SEPARATOR, 0 });
	ft_strcpy(full_path + path_len + 1, *b->args);
	if ((res = access(full_path, F_OK)) == OK &&
		(res = sh_is_dir(full_path)) == OK)
		sh_exec(full_path, b);
	ft_strdel(&full_path);
	return (res ? false : true);
}

void		sh_update_curent_dir_name(void)
{
	char	*home;
	char	*file;

	if (((home = env_get_vlu_by_key(sh()->env.start, HOME_ENV)) &&
		!ft_strcmp(home, sh()->pwd)))
		ft_strcpy(sh()->curent_path, (char[2]){ TILDE_C, 0 });
	else if ((file = ft_strrchr(sh()->pwd, UNIX_PATH_SEPARATOR)))
	{
		if (*(file + 1))
			++file;
		ft_strcpy(sh()->curent_path, file);
	}
	else
		ft_strcpy(sh()->curent_path, sh()->pwd);
}

void		sh_reset_settings(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &sh()->old_settings);
}

void		sh_fatal_err(const char *message)
{
	ft_dprintf(STDERR_FILENO, SH_ERR, message);
	sh_reset_settings();
	exit(EXIT_FAILURE);
}

void		sh_print_err(int32_t err_code, char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	sh()->exec_code = err_code;
	sh()->ok = false;
	ft_strdel(&message);
}
