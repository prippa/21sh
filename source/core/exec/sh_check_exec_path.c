/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_exec_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:33:43 by prippa            #+#    #+#             */
/*   Updated: 2019/05/05 18:51:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtin.h"
#include "info.h"

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

t_bool		sh_check_full_path(const char *full_path, size_t len, t_build *b)
{
	int32_t	res;
	char	*fp;

	fp = ft_strsub(full_path, 0, len);
	if ((res = access(fp, F_OK)) == OK &&
		(res = sh_is_dir(fp)) == OK)
		sh_exec(fp, b);
	ft_strdel(&fp);
	return (res ? false : true);
}
