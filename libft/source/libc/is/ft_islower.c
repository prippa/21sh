/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:13:02 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 15:13:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int32_t	ft_islower(int32_t c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
