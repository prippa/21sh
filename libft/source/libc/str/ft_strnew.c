/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:43:39 by prippa            #+#    #+#             */
/*   Updated: 2017/11/03 16:43:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

char	*ft_strnew(size_t size)
{
	char *new_obj;

	if (!(new_obj = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (new_obj);
}
