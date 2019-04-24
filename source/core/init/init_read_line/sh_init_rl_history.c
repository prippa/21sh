/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_rl_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:44:59 by prippa            #+#    #+#             */
/*   Updated: 2019/04/12 14:45:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"
#include "messages.h"
#include "get_next_line.h"

static void	sh_read_file(int32_t fd)
{
	char		*line;
	int32_t		gnl_res;

	while ((gnl_res = get_next_line(fd, &line)) > 0)
		LST_PUSH_BACK_REF(&rl()->hs.history, line, ft_strlen(line));
	if (gnl_res == ERR)
		sh_fatal_err(GNL_FAILED);
}

static char	*sh_get_path(const char *home)
{
	char	*path;
	size_t	home_len;

	home_len = ft_strlen(home);
	path = ft_memalloc(home_len + 1 + ft_strlen(HISTORY_FILE_NAME) + 1);
	ft_strcpy(path, home);
	ft_strcpy(path + home_len, (char[2]){ UNIX_PATH_SEPARATOR, 0 });
	ft_strcpy(path + home_len + 1, HISTORY_FILE_NAME);
	return (path);
}

void		sh_init_rl_histiry(void)
{
	int32_t	fd;
	char	*tmp;

	LST_INIT(&rl()->hs.history, &ft_cnt_delptr);
	if (!(tmp = getenv(HOME_ENV)))
		return ;
	rl()->hs.path_to_hs_file = sh_get_path(tmp);
	if ((fd = open(rl()->hs.path_to_hs_file,
		OPEN_RDWR_APPEND_FLAGS,
		OPEN_CREATE_RW_RIGHTS)) == ERR)
		sh_fatal_err(OPEN_ERR);
	sh_read_file(fd);
	close(fd);
}
