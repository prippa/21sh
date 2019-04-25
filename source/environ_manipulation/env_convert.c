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
#include "info.h"

static char	*env_convert_to_str(const char *key, const char *value)
{
	char	*env;
	size_t	key_size;
	size_t	value_size;

	key_size = ft_strlen(key);
	value_size = ft_strlen(value);
	env = ft_strnew(key_size + value_size + 1);
	ft_strcpy(env, key);
	ft_strcpy(env + key_size, (char[2]){ KEY_VALUE_SEPARATOR, 0 });
	ft_strcpy(env + key_size + 1, value);
	return (env);
}

char		**env_convert_to_arr(t_list_elem *start, size_t list_size)
{
	t_env	*e;
	char	**arr;
	size_t	i;

	arr = ft_memalloc(sizeof(char *) * (list_size + 1));
	i = -1;
	while (start)
	{
		e = (t_env *)start->content;
		arr[++i] = env_convert_to_str(e->key, e->value);
		start = start->next;
	}
	return (arr);
}
