/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:29:17 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 15:29:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"

void		env_del_body(t_env *e)
{
	ft_strdel(&e->key);
	ft_strdel(&e->value);
}

void		env_del_list(void *content, size_t content_size)
{
	(void)content_size;
	env_del_body((t_env *)content);
	ft_memdel(&content);
}
