/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:21:55 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:21:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include <stdlib.h>

typedef	struct		s_list_elem
{
	void				*content;
	size_t				content_size;
	struct s_list_elem	*next;
	struct s_list_elem	*prev;
}						t_list_elem;

typedef	struct			s_list
{
	t_list_elem			*start;
	t_list_elem			*end;
	size_t				list_size;
}						t_list;

typedef void (*t_del_content)(void *content, size_t content_size);
typedef void (*t_iter_elem)(t_list_elem *elem);
typedef t_list_elem *(*t_map_elem)(t_list_elem *elem);

t_list_elem				*ft_lstnew(void const *content, size_t content_size);
void					ft_lstpush_front(t_list *lst, t_list_elem *new_obj);
void					ft_lstpush_back(t_list *lst, t_list_elem *new_obj);
void					ft_lstpop_front(t_list *lst, t_del_content f);
void					ft_lstpop_back(t_list *lst, t_del_content f);

void					ft_lstdel(t_list *lst, t_del_content f);
void					ft_lstdel_one(t_list_elem **elem, t_del_content f);
void					ft_lstdel_content(void *content, size_t content_size);
void					ft_lstdel_by_obj(t_list *lst, t_list_elem *obj,
							t_del_content f);

void					ft_lstiter(t_list_elem *start, t_iter_elem f);
t_list					ft_lstmap(t_list_elem *start, t_map_elem f);

void					ft_lstrev(t_list *lst);
size_t					ft_lstsize(t_list_elem *start);

#endif
