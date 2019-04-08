/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:54:26 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 13:54:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"
#include "shell.h"

static void		env_edit(t_list_elem *obj, t_env *env)
{
	t_env	*edit_env;

	edit_env = (t_env *)obj->content;
	env_del_body(edit_env);
	ft_memcpy(edit_env, env, sizeof(t_env));
}

void			env_set(t_list *env_list,
					const t_env *new_env, t_bool overwrite)
{
	t_list_elem	*obj;
	t_env		new_env_cpy;

	new_env_cpy = env_make_clone_of_body(new_env);
	obj = env_get_obj_by_key(env_list->start, new_env_cpy.key);
	if (obj && overwrite)
		env_edit(obj, &new_env_cpy);
	else
		LST_PUSH_BACK(env_list, &new_env_cpy, sizeof(t_env));
}
