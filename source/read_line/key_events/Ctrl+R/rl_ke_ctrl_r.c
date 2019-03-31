/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:11:40 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 17:11:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"
#include "read_line_signals.h"

#define SEARCH_PROMPT "(search)'': "
#define INSERT_INDEX 9

static t_bool g_exit_from_mod;

static void	rl_kcr_init(t_line *ln)
{
	rl_clear_line(ln, rl()->w.ws_col);
	ft_strcpy(rl()->prompt, SEARCH_PROMPT);
	rl()->prompt_size = ft_strlen(SEARCH_PROMPT);
	rl_redraw_line(ln, rl()->w.ws_col);
}

static void		rl_krc_sig_handle(int32_t sig)
{
	if (sig == SIGINT)
	{
		g_exit_from_mod = true;
		rl_sig_handle(SIGWINCH);
	}
	else if (sig == SIGWINCH)
		rl_sig_handle(SIGWINCH);
}

static t_bool	rl_read(char buf[RL_BUFF_SIZE])
{
	rl_execute_aside_signals(&rl_krc_sig_handle);
	
	signal(SIGINT, rl_krc_sig_handle);
	signal(SIGWINCH, rl_krc_sig_handle);
	ft_bzero(buf, RL_BUFF_SIZE);
	if (read(STDIN_FILENO, buf, RL_BUFF_SIZE) == ERR)
		sh_fatal_err(READ_ERR);
	rl_init_sig_aside();
}

uint64_t	rl_ke_ctrl_r(t_line *ln)
{
	rl_kcr_init(ln);
	
	return (0);
}
