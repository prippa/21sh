/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:16:09 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:16:10 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ_manipulation.h"
#include "info.h"
#include "shell.h"

void	env_check_global_event(const t_env *e)
{
	if (sh()->env_exec_flag)
		return ;
	if (ft_strequ(e->key, PATH_ENV))
		env_new_path(e->value);
	if (ft_strequ(e->key, HOME_ENV))
		sh_update_current_dir_name();
}
