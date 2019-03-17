/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:44:21 by prippa            #+#    #+#             */
/*   Updated: 2018/02/26 15:44:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

char	**ft_arrnew(size_t y, size_t x, int32_t c)
{
	char	**arr;
	size_t	x_len;

	if (!(arr = (char **)ft_memalloc(sizeof(char *) * (y + 1))))
		return (NULL);
	x_len = (sizeof(char) * (x + 1));
	while (y--)
	{
		if (!(arr[y] = (char *)ft_memalloc(x_len)))
			return (NULL);
		ft_memset(arr[y], c, x_len - 1);
	}
	return (arr);
}
