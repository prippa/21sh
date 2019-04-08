/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:44:00 by prippa            #+#    #+#             */
/*   Updated: 2019/04/06 11:44:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

uint32_t	ft_ht_hash(const void *key, size_t key_size, uint32_t ht_size)
{
	const uint8_t	*ptr;
	uint32_t		hash;
	uint32_t		len;
	uint32_t		i;

	ptr = (const uint8_t *)key;
	hash = HT_MASK;
	len = 0;
	if (key_size)
		len = key_size >> 1;
	i = -1;
	while (++i < len)
		hash ^= (i << 4 ^ ptr[i] << 8 ^ ptr[i]);
	return (hash % ht_size);
}
