/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:52:59 by prippa            #+#    #+#             */
/*   Updated: 2019/04/03 17:53:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_TABLE_H
# define FT_HASH_TABLE_H

# include <stddef.h>

typedef struct	s_ht_item
{
	void		*key;
	void		*value;
	size_t		key_size;
	size_t		value_size;
}				t_ht_item;

typedef struct	s_hash_table
{
	t_ht_item	*items;
	size_t		items_size;
}				t_hash_table;

#endif
