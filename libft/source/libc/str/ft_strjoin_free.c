/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:59:59 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 13:00:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strjoin_free(char **dst, const char *src,
			size_t dstsize, size_t srcsize)
{
	char *tmp;

	tmp = *dst;
	if (!(*dst = (char *)ft_memalloc(sizeof(char) * (dstsize + srcsize + 1))))
		return (NULL);
	ft_strncpy(*dst, tmp, dstsize);
	ft_strncpy(*dst + dstsize, src, srcsize);
	free(tmp);
	return (*dst);
}
