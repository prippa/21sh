/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:33:35 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:33:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstpop_front(t_list *lst, t_del_content del)
{
	t_list_elem *del_elem;

	if (lst->start == lst->end)
		lst->end = NULL;
	del_elem = lst->start;
	lst->start = lst->start->next;
	ft_lstdel_one(&del_elem, del);
	--lst->list_size;
}

void	ft_lstpop_back(t_list *lst, t_del_content del)
{
	t_list_elem *del_elem;

	if (lst->end == lst->start)
		lst->start = NULL;
	del_elem = lst->end;
	lst->end = lst->end->prev;
	ft_lstdel_one(&del_elem, del);
	--lst->list_size;
}
