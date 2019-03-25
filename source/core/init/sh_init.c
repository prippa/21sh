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
#include "read_line.h"
#include "messages.h"

static void	sh_init_read_line(void)
{
	t_read_line *r;

	r = rl();
	GET_MEM(MALLOC_ERR, r->hs.cur_line_buf, ft_strdup, EMPTY_STR);
}

void		sh_init(void)
{
	ft_bzero(sh(), sizeof(t_shell));
	sh()->ok = true;
	GET_MEM(GETCWD_FAILED, sh()->pwd, getcwd, NULL, 0);
	sh_init_env();
	sh_init_term();
	sh_update_curent_dir_name();
	sh_update_prompt(true);
	sh_init_sig_base();
}
