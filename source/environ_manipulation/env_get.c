/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:42:12 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:42:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"

t_list_elem	*env_get_obj_by_key(t_list_elem *start, const char *key)
{
	while (start)
	{
		if (!ft_strcmp(((t_env *)start->content)->key, key))
			return (start);
		start = start->next;
	}
	return (NULL);
}

char		*env_get_vlu_by_key(t_list_elem *start, const char *key)
{
	t_env *e;

	while (start)
	{
		e = (t_env *)start->content;
		if (!ft_strcmp(e->key, key))
			return (e->value);
		start = start->next;
	}
	return (NULL);
}
