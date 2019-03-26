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

static void	sh_sigint_base_reaction(void)
{
	ft_putchar_fd('\n', STDIN_FILENO);
	sh()->exec_code = SIGINT;
}

void		sh_sig_handle_rl(int sig)
{
	t_read_line *r;

	r = rl();
	if (sig == SIGINT)
	{
		rl_ke_end(&r->ln);
		sh_sigint_base_reaction();
		sh_update_prompt(false);
		ft_memdel((void **)&r->ln.line);
		rl_init();
	}
	if (sig == SIGWINCH)
	{
		rl_clear_line();
		ioctl(STDIN_FILENO, TIOCGWINSZ, &r->w);
		rl_redraw_line(&r->ln, r->w.ws_col);
	}
}

void		sh_sig_handle_base(int sig)
{
	if (sig == SIGINT)
	{
		sh_sigint_base_reaction();
		sh_update_prompt(false);
		ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	}
}

void		sh_sig_handle_incase(int sig)
{
	if (sig == SIGINT)
	{
		sh_sigint_base_reaction();
		sh()->ok = false;
	}
}
