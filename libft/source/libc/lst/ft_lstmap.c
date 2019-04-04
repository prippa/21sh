/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:55 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:39:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "ft_mem.h"

t_list	ft_lstmap(t_list_elem *start, t_map_elem f)
{
	t_list		new_list;
	t_list_elem	*elem;

	ft_bzero(&new_list, sizeof(t_list));
	new_list.start = f(start);
	elem = new_list.start;
	while (start->next)
	{
		elem->next = f(start->next);
		elem = elem->next;
		start = start->next;
	}
	return (new_list);
}
