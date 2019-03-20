/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:15:30 by prippa            #+#    #+#             */
/*   Updated: 2019/03/20 11:15:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char		*ft_strinsert_free(char **dst, const char *src, size_t len)
{
	char	*ptr;
	size_t	src_len;

	ptr = *dst;
	src_len = ft_strlen(src);
	if (!(*dst = (char *)ft_memalloc(ft_strlen(*dst) + src_len + 1)))
		return (NULL);
	ft_strncpy(*dst, ptr, len);
	ft_strcpy(*dst + len, src);
	ft_strcpy(*dst + len + src_len, ptr + len);
	free(ptr);
	return (*dst);
}
