/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:58:08 by prippa            #+#    #+#             */
/*   Updated: 2019/04/05 15:58:09 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_mem.h"
#include "ft_def.h"

void		ft_htinit(t_hash_table *ht, size_t init_size)
{
	ft_bzero(ht, sizeof(t_hash_table));
	ht->arr = ft_memalloc(sizeof(t_ht_elem) * init_size);
	ht->ht_size = init_size;
}
