#include "ft_hash_table.h"

void		ft_htiter_all(t_hash_table *ht, t_ht_iter_f f)
{
	size_t	i;

	i = -1;
	while (++i < ht->ht_size)
		f(&ht->arr[i]);
}

void		ft_htiter_exist(t_hash_table *ht, t_ht_iter_f f)
{
	size_t	i;

	i = -1;
	while (++i < ht->ht_size)
		if (ht->arr[i].key)
			f(&ht->arr[i]);
}
