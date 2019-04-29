/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_cmd_matches.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:13:16 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 22:58:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"
#include "builtin_static_box.h"
#include "info.h"

static void		rl_t_readdir_for_bin(const char *path, struct dirent *dit)
{
	ac()->tmp_str = ft_strjoin(path, dit->d_name);
	if (!access(ac()->tmp_str, X_OK) && !sh_is_dir(ac()->tmp_str))
		rl_t_push_match(dit->d_name, ft_strlen(dit->d_name), C_WHITE, F_NONE);
	ft_strdel(&ac()->tmp_str);
}

void			rl_t_get_cmd_matches(void)
{
	size_t	i;
	char	*path;

	i = -1;
	while (++i < SH_BUILTIN_SIZE)
		rl_t_push_match(g_builtin_box[i].s,
			ft_strlen(g_builtin_box[i].s), C_WHITE, F_NONE);
	if (!sh()->bin_path.size)
	{
		path = ft_strjoin(CUR_DIR, (char[2]){UNIX_PATH_SEPARATOR, 0});
		if (access(path, F_OK) || access(path, R_OK) || access(path, X_OK))
			ft_sys_readdir(path, &rl_t_readdir_for_bin);
		ft_strdel(&path);
	}
	else
	{
		i = -1;
		while (++i < sh()->bin_path.ht_size)
			if (sh()->bin_path.arr[i].key)
				rl_t_push_match(sh()->bin_path.arr[i].key,
					sh()->bin_path.arr[i].key_size, C_WHITE, F_NONE);
	}
}
