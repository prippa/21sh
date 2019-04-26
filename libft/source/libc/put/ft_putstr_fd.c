/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:48:29 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 15:48:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int32_t fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
