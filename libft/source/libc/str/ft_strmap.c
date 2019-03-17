/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:33:28 by prippa            #+#    #+#             */
/*   Updated: 2017/11/03 17:33:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	char	*new_obj;

	if (!s || !f)
		return (NULL);
	if (!(new_obj = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	tmp = new_obj;
	while (*s)
		*tmp++ = f(*s++);
	return (new_obj);
}
