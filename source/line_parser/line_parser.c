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

static t_bool	lp_special_cases(t_line_parser *lp)
{
	if (ft_isdigit(lp->line[lp->i]) &&
		(!lp->i || lp->line[lp->i - 1] == SPACE_C))
		return (lp_check_rediraction(lp));
	return (false);
}

static void		lp_loop(t_line_parser *lp)
{
	t_ht_elem *elem;

	lp->i = 0;
	while (lp->line[lp->i])
	{
		elem = HT_GET(&sh()->pars_manager, &lp->line[lp->i], sizeof(char));
		if (elem)
			((t_func_cmd)elem->value)(lp);
		else if (!lp_special_cases(lp))
		{
			lp_write_to_arg_buf_char(&lp->cmd, lp->line[lp->i]);
			++lp->i;
		}
	}
	lp_semicolon(lp);
}

void			line_parser(void)
{
	t_line_parser lp;

	ft_bzero(&lp, sizeof(t_line_parser));
	LST_INIT(&lp.cmds, &lp_del_commands_list);
	lp.line = sh()->line;
	lp_init_commnd(&lp.cmd);
	lp_loop(&lp);
}
