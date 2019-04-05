/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:44:21 by prippa            #+#    #+#             */
/*   Updated: 2017/11/05 13:23:23 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	uint32_t	i;
	char		*new_obj;

	if (!s || !f)
		return (NULL);
	new_obj = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	i = -1;
	while (s[++i])
		new_obj[i] = f(i, s[i]);
	return (new_obj);
}
