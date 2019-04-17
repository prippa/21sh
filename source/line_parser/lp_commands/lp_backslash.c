/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:55:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

void	lp_backslash(t_line_parser *lp)
{
	lp_write_to_arg_buf_char(lp, lp->line[++lp->i]);
}
