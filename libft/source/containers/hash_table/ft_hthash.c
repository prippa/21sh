/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hthash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:44:00 by prippa            #+#    #+#             */
/*   Updated: 2019/04/06 11:44:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

size_t		ft_hthash(const void *key, size_t key_size, size_t ht_size)
{
	uint8_t	*ptr;
	size_t	hash;
	size_t	len;
	size_t	i;

	ptr = (uint8_t *)key;
	hash = HT_MASK;
	len = key_size >> 1;
	i = -1;
	while (++i < len)
		hash ^= (i << 4 ^ ptr[i] << 8 ^ ptr[i]);
	return (hash % ht_size);
}
