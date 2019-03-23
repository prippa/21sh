/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:25:37 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 12:25:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strcut_free(char **dst, size_t start, size_t end)
{
	char	*tmp;

	tmp = *dst;
	if (!(*dst = ft_memalloc((ft_strlen(*dst) - (end - start)) + 1)))
		return (NULL);
	ft_strncpy(*dst, tmp, start);
	ft_strcpy(*dst + start, tmp + end);
	free(tmp);
	return (*dst);
}
