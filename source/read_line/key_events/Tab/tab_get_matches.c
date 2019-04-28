/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_matches.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 11:40:06 by prippa            #+#    #+#             */
/*   Updated: 2019/04/28 11:54:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "auto_completion.h"
#include "info.h"
#include "environ_manipulation.h"
#include "builtin_static_box.h"

static void		rl_t_gm_push(t_list *m, const char *bc, const char *c)
{
	char	*cmd;

	if (ft_strnequ(bc, c, ft_strlen(bc)))
	{
		cmd = ft_strdup(c);
		LST_PUSH_BACK_REF(m, cmd, ft_strlen(cmd));
	}
}

static void		rl_t_read_dir(t_list *m, char **paths, const char *bc)
{
	DIR				*dip;
	struct dirent	*dit;
	char			*bin;

	--paths;
	while (*(++paths))
	{
		if (access(*paths, F_OK) || access(*paths, X_OK))
			continue ;
		if (!(dip = opendir(*paths)))
			g_fef(OPENDIR_FAILED);
		while ((dit = readdir(dip)))
		{
			bin = ft_strjoin(*paths, (char[2]){UNIX_PATH_SEPARATOR, 0});
			ft_strjoin_free(&bin, dit->d_name,
							ft_strlen(bin), ft_strlen(dit->d_name));
			if (!access(bin, X_OK) && dit->d_type != DT_DIR)
				rl_t_gm_push(m, bc, dit->d_name);
			ft_strdel(&bin);
		}
		if ((closedir(dip)) == ERR)
			g_fef(CLOSEDIR_FAILED);
	}
}

t_list			rl_t_get_cmd_matches(const char *bc)
{
	size_t	i;
	t_list	m;
	char	**paths;
	char	*path_env;

	LST_INIT(&m, &ft_cnt_delptr);
	i = -1;
	while (++i < SH_BUILTIN_SIZE)
		rl_t_gm_push(&m, bc, g_builtin_box[i].s);
	if (!(path_env = env_get_vlu_by_key(sh()->env.start, PATH_ENV)))
		path_env = CUR_DIR;
	paths = ft_strsplit(path_env, PATH_ENV_SEPARATOR);
	rl_t_read_dir(&m, paths, bc);
	ft_arrdel(&paths);
	return (m);
}

t_list			rl_t_get_path_matches(const char *bc)
{
	t_list	m;

	LST_INIT(&m, &ft_cnt_delptr);
	return (m);
}
