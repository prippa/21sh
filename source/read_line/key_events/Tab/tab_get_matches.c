/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_matches.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 11:40:06 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 12:49:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "auto_completion.h"
#include "info.h"
#include "environ_manipulation.h"
#include "builtin_static_box.h"

static void		rl_t_gm_push(t_list *m, const char *bc,
					const char *c, size_t c_len)
{
	char	*cmd;
	size_t	bc_len;

	bc_len = ft_strlen(bc);
	if (bc_len <= c_len && ft_strnequ(bc, c, bc_len))
	{
		cmd = ft_strsub(c, 0, c_len);
		LST_PUSH_BACK_REF(m, cmd, ft_strlen(cmd));
	}
}

static void		rl_t_read_for_bin(t_list *m,
					const char *path, const char *match)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*path_with_us;
	char			*bin;

	if (access(path, F_OK) || access(path, R_OK) || access(path, X_OK))
		return ;
	if (!(dip = opendir(path)))
		g_fef(OPENDIR_FAILED);
	path_with_us = ft_strjoin(path, (char[2]){UNIX_PATH_SEPARATOR, 0});
	while ((dit = readdir(dip)))
	{
		bin = ft_strjoin(path_with_us, dit->d_name);
		if (!access(bin, X_OK) && dit->d_type != DT_DIR)
			rl_t_gm_push(m, match, dit->d_name, ft_strlen(dit->d_name));
		ft_strdel(&bin);
	}
	if ((closedir(dip)) == ERR)
		g_fef(CLOSEDIR_FAILED);
	ft_strdel(&path_with_us);
}

t_list			rl_t_get_cmd_matches(const char *bc)
{
	size_t	i;
	t_list	m;

	LST_INIT(&m, &ft_cnt_delptr);
	i = -1;
	while (++i < SH_BUILTIN_SIZE)
		rl_t_gm_push(&m, bc, g_builtin_box[i].s, ft_strlen(g_builtin_box[i].s));
	if (!sh()->bin_path.size)
		rl_t_read_for_bin(&m, CUR_DIR, bc);
	else
	{
		i = -1;
		while (++i < sh()->bin_path.ht_size)
			if (sh()->bin_path.arr[i].key)
				rl_t_gm_push(&m, bc,
					sh()->bin_path.arr[i].key, sh()->bin_path.arr[i].key_size);
	}
	return (m);
}

static void		rl_t_read_dir_for_path(t_list *m, const char *path, const char *match)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*file;

	if (!(dip = opendir(path)))
		g_fef(OPENDIR_FAILED);
	while ((dit = readdir(dip)))
	{
		if (*match ||
			(!ft_strequ(dit->d_name, CUR_DIR) &&
			!ft_strequ(dit->d_name, PREV_DIR)))
		{
			file = ft_strdup(dit->d_name);
			if (dit->d_type == DT_DIR)
				ft_strjoin_free(&file, (char[2]){UNIX_PATH_SEPARATOR, 0},
					ft_strlen(file), 1);
			rl_t_gm_push(m, match, file, ft_strlen(file));
			ft_strdel(&file);
		}
	}
	if ((closedir(dip)) == ERR)
		g_fef(CLOSEDIR_FAILED);
}

t_list			rl_t_get_path_matches(char **bc)
{
	t_list		m;
	const char	*match;
	char		*path;

	LST_INIT(&m, &ft_cnt_delptr);
	if ((match = ft_strrchr(*bc, UNIX_PATH_SEPARATOR)))
	{
		path = ft_strsub(*bc, 0, match - *bc + 1);
		ft_strdup_free(bc, ++match);
	}
	else
		path = ft_strdup(CUR_DIR);
	match = *bc;
	rl_t_read_dir_for_path(&m, path, match);
	ft_strdel(&path);
	return (m);
}
