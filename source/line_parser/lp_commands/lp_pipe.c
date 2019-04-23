/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:07:42 by prippa            #+#    #+#             */
/*   Updated: 2019/04/17 14:07:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "messages.h"

void		lp_pipe(t_line_parser *lp)
{
	lp_add_cmd(lp);
	++lp->i;
}