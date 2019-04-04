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
		#include <stdio.h>

void	ft_lstpop_front(t_list *lst, t_del_content del)
{
	t_list_elem *tmp;

	if (!lst->start)
		return ;
	tmp = lst->start;
	lst->start = lst->start->next;
	if (lst->start)
		lst->start->prev = NULL;
	else
		lst->end = NULL;
	ft_lstdel_one(&tmp, del);
	--lst->list_size;
}

void	ft_lstpop_back(t_list *lst, t_del_content del)
{
	t_list_elem *tmp;

	if (!lst->end)
		return ;
	tmp = lst->end;
	lst->end = lst->end->prev;
	if (lst->end)
		lst->end->prev = NULL;
	else
		lst->end = NULL;
	ft_lstdel_one(&tmp, del);
	--lst->list_size;
}
