/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:14:36 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 18:14:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_def.h"
#include "ft_other.h"
#include "ft_mem.h"

void	fpf_init_random_char(t_printf *fpf)
{
	if (!(fpf->str = (char *)ft_memalloc(sizeof(char) * 2)))
		ft_perror_exit(MALLOC_ERR);
	fpf->str[0] = *fpf->format;
	fpf->type = 'c';
	++fpf->format;
}
