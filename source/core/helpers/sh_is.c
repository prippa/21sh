/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:02 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 01:04:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "info.h"
#include <sys/stat.h>

t_bool		sh_is_dir(const char *path)
{
	struct stat	sb;

	if ((stat(path, &sb)) == ERR)
		return (false);
	return (S_ISDIR(sb.st_mode));
}

t_bool		sh_is_valid_path_len(const char *path)
{
	uint16_t	i;

	if (ft_strlen(path) >= PATH_MAX)
		return (true);
	i = 0;
	while (*path)
	{
		if (*path == UNIX_PATH_SEPARATOR)
			i = 0;
		else if (++i > 255)
			return (true);
		++path;
	}
	return (false);
}
