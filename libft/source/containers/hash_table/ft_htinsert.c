/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:55:42 by prippa            #+#    #+#             */
/*   Updated: 2019/04/05 13:55:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_mem.h"
#include "ft_def.h"

static void	ft_ht_increase_size(t_hash_table *ht)
{
	t_ht_elem	*new_arr;
	size_t		new_ht_size;

	new_ht_size = ht->ht_size << 1;
	new_arr = ft_memalloc(sizeof(t_ht_elem) * new_ht_size);
	ft_memcpy(new_arr, ht->arr, sizeof(t_ht_elem) * ht->ht_size);
	ft_memdel((void **)&ht->arr);
	ht->arr = new_arr;
	ht->ht_size = new_ht_size;
}

static void	ft_ht_make_insert_op(t_hash_table *ht, t_ht_elem *item)
{
	size_t	hash;

	hash = ft_hthash(item->key, item->key_size, ht->ht_size);
	while (true)
	{
		// if (ht->arr[hash].key)
	}
}

void		ft_htinset(t_hash_table *ht, t_ht_elem *item)
{
	if (!ht->ht_size)
	{
		ft_htinit(ht, HT_ELEM_SPACE);
		ft_ht_make_insert_op(ht, item);
		return ;
	}
	if (ht->size * HT_ELEM_SPACE + 1 > ht->ht_size)
		ft_ht_increase_size(ht);
	ft_ht_make_insert_op(ht, item);
}
