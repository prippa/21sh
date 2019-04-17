/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:41:49 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:41:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"

static void			lp_loop(t_line_parser *lp)
{
	t_ht_elem *elem;

	lp->i = -1;
	while (lp->line[++lp->i])
	{
		elem = HT_GET(&sh()->pars_manager, &lp->line[lp->i], sizeof(char));
		if (elem)
			((t_func_cmd)elem->value)(lp);
		else
			lp_write_to_arg_buf_char(lp, lp->line[lp->i]);
	}
	lp_push_command(lp);
}

void				line_parser(void)
{
	t_line_parser lp;

	ft_bzero(&lp, sizeof(t_line_parser));
	lp.line = sh()->line;
	LST_INIT(&lp.cmds, &ft_cnt_delptr);
	lp_loop(&lp);
}
