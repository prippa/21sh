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

# include "ft_def.h"
# include <stddef.h>

# define HT_MASK 0xbabe
# define HT_ELEM_SPACE 2.5

typedef struct s_ht_item	t_ht_elem;
typedef struct s_hash_table	t_hash_table;

typedef void	(*t_ht_del_key)(void *key, size_t key_size);
typedef void	(*t_ht_del_value)(void *value, size_t value_size);
typedef void	(*t_ht_iter_f)(t_ht_elem *elem);

struct				s_ht_item
{
	void			*key;
	void			*value;
	size_t			key_size;
	size_t			value_size;
};

struct				s_hash_table
{
	t_ht_elem		*arr;
	size_t			size;
	size_t			ht_size;
	t_ht_del_key	del_key;
	t_ht_del_value	del_value;
};

# define HT_ELEM_BLOCK {.key = k, .value = v, .key_size = ks, .value_size = vs}
# define HT_ELEM(k, v, ks, vs) &(t_ht_elem)HT_ELEM_BLOCK

void				ft_htinit(t_hash_table *ht, size_t init_size);
size_t				ft_hthash(const void *key, size_t key_size, size_t ht_size);

void				ft_htinsert(t_hash_table *ht, const t_ht_elem *elem);
void				ft_htinsert_ref(t_hash_table *ht, const t_ht_elem *elem);
void				ft_htinsert_logic(t_hash_table *ht,
						const t_ht_elem *elem, t_bool ref);

void				ft_htiter_all(t_hash_table *ht, t_ht_iter_f f);
void				ft_htiter_exist(t_hash_table *ht, t_ht_iter_f f);


#endif
