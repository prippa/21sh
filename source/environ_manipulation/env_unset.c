/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:54:46 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 13:43:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"

int32_t		env_unset(t_list *env_list, const char *key)
{
	t_list_elem	*obj;

	if (!(obj = env_get_obj_by_key(env_list->start, key)))
		return (ERR);
	ft_lstdel_by_obj(env_list, obj);
	env_check_global_event_unset(key);
	return (0);
}
