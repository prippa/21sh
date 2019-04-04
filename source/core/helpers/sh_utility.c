/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 18:10:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "syntax_characters.h"
#include "environ_manipulation.h"

#define SH_ERR		"ERROR: " SHELL_NAME " : %s\n"

void		sh_lstpush_back(t_list *lst, t_bool make_copy_of_content,
				void *content, size_t content_size)
{
	t_list_elem *new_obj;

	if (make_copy_of_content)
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_lstnew, content, content_size);
	}
	else
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_memalloc, sizeof(t_list_elem));
		new_obj->content = content;
		new_obj->content_size = content_size;
	}
	ft_lstpush_back(lst, new_obj);
}

void		sh_update_curent_dir_name(void)
{
	char	*home;
	char	*file;

	if (((home = env_get_vlu_by_key(sh()->env.start, HOME_ENV)) &&
		!ft_strcmp(home, sh()->pwd)))
		ft_strcpy(sh()->curent_path, (char[2]){ TILDE_C, 0 });
	else if ((file = ft_strrchr(sh()->pwd, UNIX_PATH_SEPARATOR)))
	{
		if (*(file + 1))
			++file;
		ft_strcpy(sh()->curent_path, file);
	}
	else
		ft_strcpy(sh()->curent_path, sh()->pwd);
}

void		sh_reset_settings(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &sh()->old_settings);
}

void		sh_fatal_err(const char *message)
{
	ft_dprintf(STDERR_FILENO, SH_ERR, message);
	sh_reset_settings();
	exit(EXIT_FAILURE);
}
