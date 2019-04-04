/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:45:57 by prippa            #+#    #+#             */
/*   Updated: 2019/04/04 15:45:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

size_t	ft_lstsize(t_list_elem *start)
{
	size_t size;

	size = 0;
	while (start)
	{
		++size;
		start = start->next;
	}
	return (size);
}
