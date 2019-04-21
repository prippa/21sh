/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:16:33 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:16:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"

t_bool		lp_check_rediraction(t_line_parser *lp)
{
	size_t		i;
	intmax_t	n;

	i = lp->i;
	while (ft_isdigit(lp->line[++i]))
		;
	if (lp->line[i] == REDIRECT_IN_C || lp->line[i] == REDIRECT_OUT_C)
	{
		n = ft_atoi_max(&lp->line[lp->i]);
		if (n > INT32_MAX)
			return (false);
		if (lp->line[i] == REDIRECT_IN_C)
			lp_redirect_in(lp);
		if (lp->line[i] == REDIRECT_OUT_C)
			lp_redirect_out(lp);
		return (true);
	}
	return (false);
}
