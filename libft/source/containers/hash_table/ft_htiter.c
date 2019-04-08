#include "ft_hash_table.h"

void		ft_htiter_all(t_hash_table *ht, t_ht_iter_f f)
{
	uint32_t	i;
	uint32_t	size;

	i = -1;
	size = ht->ht_size;
	while (++i < size)
		f(&ht->arr[i]);
}

void		ft_htiter_exist(t_hash_table *ht, t_ht_iter_f f)
{
	uint32_t	i;
	uint32_t	size;

	i = -1;
	size = ht->ht_size;
	while (++i < size)
		if (ht->arr[i].key)
			f(&ht->arr[i]);
}
