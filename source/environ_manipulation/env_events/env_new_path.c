/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:16:15 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:16:17 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include <dirent.h>

static void	env_np_list_folder(char *dir)
{
	DIR				*dip;
	struct dirent	*dit;

	if (!(dip = opendir(dir)))
		sh_fatal_err(OPENDIR_FAILED);
	while ((dit = readdir(dip)))
		if (dit->d_type != DT_DIR)
			HT_INSERT(&sh()->bin_path, dit->d_name, dir,
				ft_strlen(dit->d_name), ft_strlen(dir));
	if ((closedir(dip)) == ERR)
		sh_fatal_err(CLOSEDIR_FAILED);
}

void		env_new_path(const char *paths_str)
{
	char		**paths;
	uint32_t	i;

	if (sh()->bin_path.arr)
		HT_DEL(&sh()->bin_path);
	HT_INIT(&sh()->bin_path, 0, &ft_cnt_delptr, &ft_cnt_delptr);
	paths = ft_strsplit(paths_str, PATH_ENV_SEPARATOR);
	i = -1;
	while (paths[++i])
		if (access(paths[i], R_OK) == OK)
			env_np_list_folder(paths[i]);
	ft_arrdel(&paths);
}
