/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:38 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:55:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"

void	lp_backslash(t_line_parser *lp)
{
	lp_write_to_arg_buf_char(&lp->cmd, lp->line[++lp->i]);
	++lp->i;
}
