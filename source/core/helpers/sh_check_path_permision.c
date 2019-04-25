/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_path_permision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:32:09 by prippa            #+#    #+#             */
/*   Updated: 2019/02/25 12:32:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "info.h"

static t_bool	sh_path_access_check(char *s, size_t i,
					const char *path, const char *prefix)
{
	t_bool	res;

	res = true;
	s[i] = 0;
	if (access(s, F_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		sh_print_err(EXIT_FAILURE, MSG(NO_FILE_OR_DIR, path));
	}
	else if (access(s, X_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		sh_print_err(EXIT_FAILURE, MSG(PERM_DENIED, path));
	}
	else
		res = false;
	s[i] = UNIX_PATH_SEPARATOR;
	return (res);
}

static t_bool	sh_path_access_loop(char *s, const char *path,
					const char *prefix)
{
	size_t	i;

	i = -1;
	if (*s == UNIX_PATH_SEPARATOR)
		++i;
	while (s[++i])
		if (s[i] == UNIX_PATH_SEPARATOR &&
			sh_path_access_check(s, i, path, prefix))
			return (true);
	if (access(s, F_OK))
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		sh_print_err(EXIT_FAILURE, MSG(NO_FILE_OR_DIR, s));
		return (true);
	}
	return (false);
}

t_bool			sh_path_access(const char *path, const char *prefix)
{
	char	*s;
	t_bool	res;

	s = ft_strdup(path);
	res = sh_path_access_loop(s, path, prefix);
	ft_strdel(&s);
	return (res);
}
