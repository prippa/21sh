#include "ft_hash_table.h"
#include "ft_mem.h"

static void	ft_ht_new_value(t_ht_elem *dst, const t_ht_elem *src, t_bool ref)
{
	if (!ref)
	{
		if (src->value)
		{
			dst->value = ft_memalloc(src->value_size);
			ft_memcpy(dst->value, src->value, src->value_size);
			dst->value_size = src->value_size;
		}
		else
		{
			dst->value = NULL;
			dst->value_size = 0;
		}
	}
	else
	{
		dst->value = src->value;
		if (src->value)
			dst->value_size = src->value_size;
		else
			dst->value_size = 0;
	}
}

static void	ft_ht_insert_move(t_ht_elem *dst,
				const t_ht_elem *src, t_bool ref)
{
	if (!ref)
	{
		dst->key = ft_memalloc(src->key_size);
		ft_memcpy(dst->key, src->key, src->key_size);
		dst->key_size = src->key_size;
		ft_ht_new_value(dst, src, ref);
	}
	else
	{
		dst->key = src->key;
		dst->key_size = src->key_size;
		ft_ht_new_value(dst, src, ref);
	}
}

static void	ft_ht_make_insert_op(t_hash_table *ht,
				const t_ht_elem *elem, t_bool ref)
{
	size_t	hash;

	hash = ft_hthash(elem->key, elem->key_size, ht->ht_size);
	while (true)
	{
		if (!ht->arr[hash].key)
		{
			ft_ht_insert_move(&ht->arr[hash], elem, ref);
			break ;
		}
		if (ht->arr[hash].key_size == elem->key_size &&
			ft_memcmp(ht->arr[hash].key, elem->key, elem->key_size))
		{
			ht->del_value(ht->arr[hash].value, ht->arr[hash].value_size);
			ft_ht_new_value(&ht->arr[hash], elem, ref);
			break ;
		}
		hash = ((hash + 1) % ht->ht_size);
	}
}

static void	ft_ht_increase_arr_size(t_hash_table *ht)
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

void	ft_htinsert_logic(t_hash_table *ht,
			const t_ht_elem *elem, t_bool ref)
{
	if (!elem || !elem->key)
		return ;
	if (!ht->ht_size)
	{
		ft_htinit(ht, HT_ELEM_SPACE);
		ft_ht_make_insert_op(ht, elem, ref);
		return ;
	}
	if (ht->size * HT_ELEM_SPACE + 1 > ht->ht_size)
		ft_ht_increase_arr_size(ht);
	ft_ht_make_insert_op(ht, elem, ref);
}
