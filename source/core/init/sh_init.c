/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:53:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "messages.h"
#include "environ_manipulation.h"

t_shell		*sh(void)
{
	static t_shell sh;

	return (&sh);
}

void		sh_init(void)
{
	g_fef = &sh_fatal_err;
	sh()->env.del = &env_del_list;
	sh_init_term();
	if (!(sh()->pwd = getcwd(NULL, 0)))
		sh_fatal_err(GETCWD_FAILED);
	sh_init_env();
	sh_update_curent_dir_name();
	sh()->ok = true;
	sh_update_prompt(true);
	sh_init_sig_base();
}
