/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:30:18 by prippa            #+#    #+#             */
/*   Updated: 2019/04/05 12:30:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include "ft_cnt_general.h"

typedef struct s_list_elem	t_list_elem;
typedef struct s_list		t_list;

typedef void	(*t_iter_elem)(t_list_elem *elem);
typedef t_list_elem *(*t_map_elem)(t_list_elem *elem);

struct					s_list_elem
{
	void				*content;
	size_t				content_size;
	struct s_list_elem	*next;
	struct s_list_elem	*prev;
};

struct					s_list
{
	t_list_elem			*start;
	t_list_elem			*end;
	size_t				list_size;
	t_delptr			del;
};

void					ft_lstinit(t_list *lst, t_delptr del_list_func);

t_list_elem				*ft_lstnew(void const *content, size_t content_size);
t_list_elem				*ft_lstnew_ref(void *content, size_t content_size);
void					ft_lstpush_back(t_list *lst, t_list_elem *new_obj);
void					ft_lstpush_front(t_list *lst, t_list_elem *new_obj);
void					ft_lstpop_back(t_list *lst);
void					ft_lstpop_front(t_list *lst);

void					ft_lstdel(t_list *lst);
void					ft_lstdel_one(t_list_elem **elem, t_delptr f);
void					ft_lstdel_by_obj(t_list *lst, t_list_elem *obj);

void					ft_lstiter(t_list *lst, t_iter_elem f);
t_list					ft_lstmap(t_list *lst, t_map_elem f);

void					ft_lstrev(t_list *lst);

# define LST_NEW(c, cs) ft_lstnew(c, cs)
# define LST_NEW_REF(c, cs) ft_lstnew_ref(c, cs)

# define LST_PUSH_BACK(l,c,cs) ft_lstpush_back(l, LST_NEW(c, cs))
# define LST_PUSH_BACK_REF(l,c,cs) ft_lstpush_back(l, LST_NEW_REF(c, cs))
# define LST_PUSH_FRONT(l,c,cs) ft_lstpush_front(l, LST_NEW(c, cs))
# define LST_PUSH_FRONT_REF(l,c,cs) ft_lstpush_front(l, LST_NEW_REF(c, cs))

#endif
