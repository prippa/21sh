/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_single_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:56:46 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:56:48 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"

void	lp_single_quotes(t_line_parser *lp)
{
	const char	*start;
	size_t		len;

	len = 0;
	start = &lp->line[++lp->i];
	while (lp->line[lp->i] != SINGLE_QUOTES_C)
	{
		++len;
		++lp->i;
	}
	if (len)
		lp_write_to_arg_buf_str(lp, start, len);
	++lp->i;
}
