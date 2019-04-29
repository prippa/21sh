/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:16:15 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 15:14:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "info.h"
#include <dirent.h>

static void	env_np_list_folder(char **dir)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*full_path;
	char			*path;

	if (!(dip = opendir(*dir)))
		g_fef(OPENDIR_FAILED);
	path = ft_strjoin(*dir, (char[2]){UNIX_PATH_SEPARATOR, 0});
	while ((dit = readdir(dip)))
	{
		full_path = ft_strjoin(path, dit->d_name);
		if (!access(full_path, X_OK) && !sh_is_dir(full_path))
			HT_INSERT(&sh()->bin_path, dit->d_name, *dir,
				ft_strlen(dit->d_name), ft_strlen(*dir));
		ft_strdel(&full_path);
	}
	if ((closedir(dip)) == ERR)
		g_fef(CLOSEDIR_FAILED);
	ft_strdel(&path);
}

void		env_new_path(const char *paths_str)
{
	char		**paths;
	uint32_t	i;

	if (sh()->bin_path.arr)
		HT_CLEAR(&sh()->bin_path);
	paths = ft_strsplit(paths_str, PATH_ENV_SEPARATOR);
	i = -1;
	while (paths[++i])
		if (!access(paths[i], R_OK) && !access(paths[i], X_OK))
			env_np_list_folder(&paths[i]);
	ft_arrdel(&paths);
}
