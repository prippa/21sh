/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_matches.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 11:40:06 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 17:34:16 by prippa           ###   ########.fr       */
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
	char			*bin;

	if (access(path, F_OK) || access(path, R_OK) || access(path, X_OK))
		return ;
	if (!(dip = opendir(path)))
		g_fef(OPENDIR_FAILED);
	while ((dit = readdir(dip)))
	{
		bin = ft_strjoin(path, dit->d_name);
		if (!access(bin, X_OK) && !sh_is_dir(bin))
			rl_t_gm_push(m, match, dit->d_name, ft_strlen(dit->d_name));
		ft_strdel(&bin);
	}
	if ((closedir(dip)) == ERR)
		g_fef(CLOSEDIR_FAILED);
}

t_list			rl_t_get_cmd_matches(const char *bc)
{
	size_t	i;
	t_list	m;
	char	*path;

	LST_INIT(&m, &ft_cnt_delptr);
	i = -1;
	while (++i < SH_BUILTIN_SIZE)
		rl_t_gm_push(&m, bc, g_builtin_box[i].s, ft_strlen(g_builtin_box[i].s));
	if (!sh()->bin_path.size)
	{
		path = ft_strjoin(CUR_DIR, (char[2]){UNIX_PATH_SEPARATOR, 0});
		rl_t_read_for_bin(&m, path, bc);
		ft_strdel(&path);
	}
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

static void		rl_t_read_dir_for_path(t_list *m,
					const char *path, const char *match)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*file;

	if (!(dip = opendir(path)))
		g_fef(OPENDIR_FAILED);
	while ((dit = readdir(dip)))
	{
		if (!*match &&
			(ft_strequ(dit->d_name, CUR_DIR) ||
			ft_strequ(dit->d_name, PREV_DIR)))
			continue ;
		file = ft_strjoin(path, dit->d_name);
		if (sh_is_dir(file))
		{
			ft_strdel(&file);
			file = ft_strjoin(dit->d_name, (char[2]){UNIX_PATH_SEPARATOR, 0});
		}
		else
			ft_strdup_free(&file, dit->d_name);
		rl_t_gm_push(m, match, file, ft_strlen(file));
		ft_strdel(&file);
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
		ft_strjoin_free(&path, (char[2]){UNIX_PATH_SEPARATOR, 0},
			ft_strlen(path), 1);
		ft_strdup_free(bc, ++match);
	}
	else
		path = ft_strjoin(CUR_DIR, (char[2]){UNIX_PATH_SEPARATOR, 0});
	match = *bc;
	rl_t_read_dir_for_path(&m, path, match);
	ft_strdel(&path);
	return (m);
}
