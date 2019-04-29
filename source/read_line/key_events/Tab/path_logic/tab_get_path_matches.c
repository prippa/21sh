/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_path_matches.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:13:28 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 00:42:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"
#include "info.h"
#include <sys/stat.h>

static void	rl_t_set_default_color(void)
{
	ac()->color_type = F_NONE;
	ac()->color = C_WHITE;
}

static void	rl_t_set_color(const char *file)
{
	struct stat	sb;

	rl_t_set_default_color();
	if (lstat(file, &sb) == ERR)
		return ;
	if (S_ISLNK(sb.st_mode))
	{
		ac()->color_type = F_NONE;
		ac()->color = C_MAGENTA;
	}
	else if (S_ISDIR(sb.st_mode))
	{
		ac()->color_type = CT_BOLD;
		ac()->color = C_YELLOW;
	}
	else if (sb.st_mode & S_IXUSR)
	{
		ac()->color_type = F_NONE;
		ac()->color = C_RED;
	}
}

static void	rl_t_readdir_for_path(const char *path, struct dirent *dit)
{
	if (!*ac()->input_word &&
		(ft_strequ(dit->d_name, CUR_DIR) ||
		ft_strequ(dit->d_name, PREV_DIR)))
		return ;
	ac()->tmp_str = ft_strjoin(path, dit->d_name);
	rl_t_set_color(ac()->tmp_str);
	if (sh_is_dir(ac()->tmp_str))
	{
		ft_strdel(&ac()->tmp_str);
		ac()->tmp_str = ft_strjoin(dit->d_name,
			(char[2]){UNIX_PATH_SEPARATOR, 0});
	}
	else
		ft_strdup_free(&ac()->tmp_str, dit->d_name);
	rl_t_push_match(ac()->tmp_str, ft_strlen(ac()->tmp_str),
		ac()->color, ac()->color_type);
	ft_strdel(&ac()->tmp_str);
}

void		rl_t_get_path_matches(void)
{
	char		*path;

	if ((ac()->tmp_str = ft_strrchr(ac()->input_word, UNIX_PATH_SEPARATOR)))
	{
		path = ft_strsub(ac()->input_word, 0,
			ac()->tmp_str - ac()->input_word + 1);
		ft_strjoin_free(&path, (char[2]){UNIX_PATH_SEPARATOR, 0},
			ft_strlen(path), 1);
		ft_strdup_free(&ac()->input_word, ++ac()->tmp_str);
	}
	else
		path = ft_strjoin(CUR_DIR, (char[2]){UNIX_PATH_SEPARATOR, 0});
	ft_sys_readdir(path, &rl_t_readdir_for_path);
	ft_strdel(&path);
}
