/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ke_ctrl_d_a_e_l_h.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:55:12 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:55:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button_keys.h"
#include "line_syntax.h"
#include "builtin.h"
#include "heredoc.h"

int32_t	rl_ke_ctrl_d(t_line *ln)
{
	if (ft_is_str_empty(ln->line))
		sh_exit(NULL);
	if (rl()->inh && ln->l_start == ln->l_end)
	{
		if (rl()->inh == LS_HEREDOC)
		{
			hd_close(ln);
			return (rl_ke_return(ln));
		}
		else if (rl()->inh == LS_Q || rl()->inh == LS_DQ)
			rl_ls_syntax_err_wtf_eof_for_quote();
		rl_ls_syntax_err_wtf_eof();
		return (RL_BREAK);
	}
	return (ERR);
}

int32_t	rl_ke_ctrl_a(t_line *ln)
{
	return (rl_ke_home(ln));
}

int32_t	rl_ke_ctrl_e(t_line *ln)
{
	return (rl_ke_end(ln));
}

int32_t	rl_ke_ctrl_l(t_line *ln)
{
	rl_make_tc_magic(tc()->cl);
	rl_redraw_line(ln, rl()->w.ws_col);
	return (OK);
}

int32_t	rl_ke_ctrl_h(t_line *ln)
{
	t_line		tmp;

	ft_bzero(&tmp, sizeof(t_line));
	rl_line_cpy(&tmp, ln);
	rl_line_cpy(ln, &rl()->prev_ln);
	rl_line_cpy(&rl()->prev_ln, &tmp);
	rl_clear_line(&tmp, rl()->w.ws_col);
	rl_redraw_line(ln, rl()->w.ws_col);
	rl_line_del(&tmp);
	return (OK);
}
