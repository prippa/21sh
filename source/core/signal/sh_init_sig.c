/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:07:58 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:07:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "signal.h"

void		sh_init_sig_rl(void)
{
	signal(SIGINT, sh_sig_handle_rl);
	signal(SIGWINCH, sh_sig_handle_rl);
}

void		sh_init_sig_base(void)
{
	signal(SIGINT, sh_sig_handle_base);
}

void		sh_init_sig_incase(void)
{
	signal(SIGINT, sh_sig_handle_incase);
}

void		sh_init_sig_default(void)
{
	signal(SIGINT, SIG_DFL);
}
