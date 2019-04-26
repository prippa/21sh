/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_make_clone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:28:01 by prippa            #+#    #+#             */
/*   Updated: 2019/03/03 14:28:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"
#include "shell.h"

t_env		env_make_clone_of_body(const t_env *origin)
{
	t_env	cpy;

	cpy.key = ft_strdup(origin->key);
	cpy.value = ft_strdup(origin->value);
	return (cpy);
}

void		env_make_clone(t_list *dst, t_list_elem *src_start)
{
	t_env	e;

	while (src_start)
	{
		e = env_make_clone_of_body(src_start->content);
		LST_PUSH_BACK(dst, &e, sizeof(t_env));
		src_start = src_start->next;
	}
}
