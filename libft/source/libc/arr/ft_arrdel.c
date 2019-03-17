/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:29:03 by prippa            #+#    #+#             */
/*   Updated: 2018/01/22 14:29:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_arrdel(char ***arr)
{
	char **tmp;

	if (arr && *arr)
	{
		tmp = *arr;
		while (*tmp)
			free(*tmp++);
		free(*arr);
		*arr = NULL;
	}
}
