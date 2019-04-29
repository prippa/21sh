/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_path_input_word.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:13:22 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 22:13:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"
#include "info.h"
#include "syntax_characters.h"
#include "environ_manipulation.h"

static void		rl_t_manage_tilde(void)
{
	const char	*home;
	char		*new_path;

	if ((home = env_get_vlu_by_key(sh()->env.start, HOME_ENV)))
	{
		new_path = ft_strdup(home);
		ft_strjoin_free(&new_path, ac()->input_word + 1,
			ft_strlen(new_path), ft_strlen(ac()->input_word + 1));
		ft_strdel(&ac()->input_word);
		ac()->input_word = new_path;
	}
}

static t_bool	rl_t_check_path_access(void)
{
	char		*as_path;
	t_bool		res;

	res = true;
	if ((as_path = ft_strrchr(ac()->input_word, UNIX_PATH_SEPARATOR)))
	{
		as_path = ft_strsub(ac()->input_word, 0,
			as_path - ac()->input_word + 1);
		if (access(as_path, F_OK) == ERR)
			res = false;
	}
	ft_strdel(&as_path);
	return (res);
}

t_bool			rl_t_get_path_input_word(t_line *ln)
{
	size_t	len;
	size_t	size;

	size = ln->pc;
	len = 0;
	while (size--)
	{
		if (ft_isspace(ln->line[size]))
			break ;
		++len;
	}
	ac()->input_word = ft_strsub(ln->line, ln->pc - len, len);
	if (*ac()->input_word == TILDE_C)
		rl_t_manage_tilde();
	return (rl_t_check_path_access());
}
