/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_in_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:36:03 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:36:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is.h"

int32_t	ft_isalpha_in_case(int32_t c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}