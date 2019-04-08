#include "ft_hash_table.h"
#include "ft_mem.h"

void	ft_htremove(t_hash_table *ht, const void *key, size_t key_size)
{
	t_ht_elem *elem;

	if (!(elem = ft_htget(ht, key, key_size)))
		return ;
	if (ht->del_key)
		ht->del_key(elem->key, elem->key_size);
	if (ht->del_value)
		ht->del_value(elem->value, elem->value_size);
	ft_bzero(elem, sizeof(t_ht_elem));
	--ht->size;
	if (ht->size * HT_ELEM_SPACE - 1 < ht->ht_size / 2)
		ft_ht_decrease_arr_size(ht);
}
