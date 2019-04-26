/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:08:49 by prippa            #+#    #+#             */
/*   Updated: 2017/10/31 13:08:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < dstlen)
		return (dstsize + srclen);
	i = dstlen;
	--dstsize;
	while (*src && i < dstsize)
		dst[i++] = *src++;
	dst[i] = 0;
	return (dstlen + srclen);
}
