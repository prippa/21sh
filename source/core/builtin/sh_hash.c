/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:14:46 by prippa            #+#    #+#             */
/*   Updated: 2019/05/05 17:35:36 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "shell.h"
#include "info.h"

#define HASH_IS_EMPTY HASH_CMD ": hash table empty"
#define HASH_CMD_NOT_FOUND HASH_CMD ": %s: not found"

void	sh_search_cmd(char **args)
{
	while (*args)
	{
		if (!HT_GET(&sh()->bin_path, *args, ft_strlen(*args)))
			sh_print_err(EXIT_FAILURE, MSG(HASH_CMD_NOT_FOUND, *args));
		++args;
	}
}

void	sh_print_hash(t_ht_elem *elem)
{
	write(STDOUT_FILENO, elem->key, elem->key_size);
	ft_putchar(HASH_SEPARATOR);
	write(STDOUT_FILENO, elem->value, elem->value_size);
	ft_putchar(ENDL);
}

void	sh_hash(t_build *b)
{
	if (*b->args)
		sh_search_cmd(b->args);
	else if (!sh()->bin_path.size)
		sh_print_err(EXIT_FAILURE, MSG(HASH_IS_EMPTY, NULL));
	else
		ft_htiter_exist(&sh()->bin_path, &sh_print_hash);
}
