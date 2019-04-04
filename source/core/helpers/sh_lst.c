/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:10:55 by prippa            #+#    #+#             */
/*   Updated: 2019/04/04 15:10:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_lstpush_back(t_list *lst, t_bool make_copy_of_content,
			void *content, size_t content_size)
{
	t_list_elem *new_obj;

	if (make_copy_of_content)
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_lstnew, content, content_size);
	}
	else
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_memalloc, sizeof(t_list_elem));
		new_obj->content = content;
		new_obj->content_size = content_size;
	}
	ft_lstpush_back(lst, new_obj);
}

void	sh_lstpush_front(t_list *lst, t_bool make_copy_of_content,
			void *content, size_t content_size)
{
	t_list_elem *new_obj;

	if (make_copy_of_content)
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_lstnew, content, content_size);
	}
	else
	{
		GET_MEM(MALLOC_ERR, new_obj, ft_memalloc, sizeof(t_list_elem));
		new_obj->content = content;
		new_obj->content_size = content_size;
	}
	ft_lstpush_front(lst, new_obj);
}
