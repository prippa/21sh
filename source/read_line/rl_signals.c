/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:52:58 by prippa            #+#    #+#             */
/*   Updated: 2019/03/28 15:53:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"
#include "read_line_signals.h"

#define SIG_SIZE 2

static struct s_sig_box	g_sig_box[SIG_SIZE] =
{
	{rl_sig_handle, false, SIGINT},
	{rl_sig_handle, false, SIGWINCH},
};

void		rl_execute_aside_signals(void)
{
	uint8_t i;

	i = -1;
	while (++i < SIG_SIZE)
		if (g_sig_box[i].flag)
		{
			g_sig_box[i].flag = false;
			g_sig_box[i].func(g_sig_box[i].sig);
		}
}

void		rl_sig_set_aside(int32_t sig)
{
	uint8_t i;

	i = -1;
	while (++i < SIG_SIZE)
		if (g_sig_box[i].sig == sig)
		{
			g_sig_box[i].flag = true;
			return ;
		}
}

void		rl_init_sig_aside(void)
{
	signal(SIGINT, rl_sig_set_aside);
	signal(SIGWINCH, rl_sig_set_aside);
}

void		rl_sig_handle(int32_t sig)
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
		rl_clear_line(&r->ln, r->w.ws_col);
		ioctl(STDIN_FILENO, TIOCGWINSZ, &r->w);
		rl_redraw_line(&r->ln, r->w.ws_col);
	}
}

void		rl_init_sig(void)
{
	signal(SIGINT, rl_sig_handle);
	signal(SIGWINCH, rl_sig_handle);
}
