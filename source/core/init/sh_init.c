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
#include "info.h"

t_shell		*sh(void)
{
	static t_shell sh;

	return (&sh);
}

void		sh_init(void)
{
	g_fef = &ft_fatal_err_exit;
	sh_init_sig_base();
	sh_init_env();
	sh_init_term();
	g_fef = &sh_fatal_err;
	sh_init_read_line();
	sh_init_line_parser();
	sh()->ok = true;
	sh_update_curent_dir_name();
	sh_update_prompt(true);
}
