/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:30:33 by prippa            #+#    #+#             */
/*   Updated: 2019/04/05 12:30:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_TABLE_H
# define FT_HASH_TABLE_H

# include <stddef.h>
# include <stdint.h>

# define HT_MASK 0xbabe
# define HT_ELEM_SPACE 2.5

typedef struct		s_ht_item
{
	void			*key;
	void			*value;
	size_t			key_size;
	size_t			value_size;
}					t_ht_elem;

typedef struct		s_hash_table
{
	t_ht_elem		*arr;
	size_t			size;
	size_t			ht_size;
}					t_hash_table;

# define HT_ELEM_BLOCK {.key = k, .value = v, .key_size = ks, .value_size = vs}
# define HT_ELEM(k, v, ks, vs) &(t_ht_elem)HT_ELEM_BLOCK

typedef void	(*t_ht_del_key)(void *key, size_t key_size);
typedef void	(*t_ht_del_value)(void *value, size_t value_size);

void				ft_htinit(t_hash_table *ht, size_t init_size);
void				ft_htinset(t_hash_table *ht, t_ht_elem *item);
size_t				ft_hthash(const void *key, size_t key_size, size_t ht_size);

#endif
