/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:47:51 by prippa            #+#    #+#             */
/*   Updated: 2017/11/03 15:47:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_def.h"
#include "ft_other.h"

void	*ft_memalloc(size_t size)
{
	void *new_obj;

	if (!(new_obj = malloc(size)))
	{
		if (g_fef)
			g_fef(MALLOC_ERR);
		else
			ft_perror_exit(MALLOC_ERR);
	}
	return (ft_memset(new_obj, 0, size));
}
