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

typedef struct		s_ht_item
{
	void			*key;
	void			*value;
	size_t			key_size;
	size_t			value_size;
}					t_ht_item;

typedef struct		s_hash_table
{
	t_ht_item		*item;
	size_t			item_size;
	size_t			item_len;
}					t_hash_table;

t_hash_table		tf_htinit(size_t size);

#endif
