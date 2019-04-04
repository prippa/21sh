/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:41:57 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 16:41:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "environ_manipulation.h"
#include "messages.h"

static char	*env_convert_to_str(const char *key, const char *value)
{
	char *env;

	GET_MEM(MALLOC_ERR, env, ft_strnew, ft_strlen(key) + ft_strlen(value) + 1);
	ft_strcpy(env, key);
	ft_strcat(env, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcat(env, value);
	return (env);
}

char		**env_convert_to_arr(t_list_elem *start)
{
	t_env	*e;
	char	**arr;
	size_t	i;

	GET_MEM(MALLOC_ERR, arr, ft_memalloc,
		sizeof(char *) * (ft_lstsize(start) + 1));
	i = -1;
	while (start)
	{
		e = (t_env *)start->content;
		arr[++i] = env_convert_to_str(e->key, e->value);
		start = start->next;
	}
	return (arr);
}
