/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sig_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:50:38 by prippa            #+#    #+#             */
/*   Updated: 2019/03/06 12:50:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"
#include <signal.h>

void		sh_sigint_base_reaction(void)
{
	ft_putchar_fd(ENDL, STDIN_FILENO);
	sh()->exec_code = SIGINT;
}

void		sh_sig_handle_base(int32_t sig)
{
	if (sig == SIGINT)
	{
		sh_sigint_base_reaction();
		sh_update_prompt(false);
		ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	}
}

void		sh_sig_handle_incase(int32_t sig)
{
	if (sig == SIGINT)
	{
		sh_sigint_base_reaction();
		sh()->ok = false;
	}
}
