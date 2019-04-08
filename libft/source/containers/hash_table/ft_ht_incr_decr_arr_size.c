#include "ft_hash_table.h"
#include "ft_mem.h"

static void	ft_ht_cpy(t_hash_table *ht, t_ht_elem *src, uint32_t ht_size)
{
	uint32_t	i;

	i = -1;
	while (++i < ht_size)
	{
		if (src[i].key)
			ft_htinsert_ref(ht, &src[i]);
	}
}

void		ft_ht_increase_arr_size(t_hash_table *ht)
{
	t_ht_elem	*old_arr;
	double		old_size;

	old_arr = ht->arr;
	old_size = ht->ht_size;
	ht->ht_size = ht->ht_size * 2;
	ht->arr = ft_memalloc(sizeof(t_ht_elem) * ht->ht_size);
	ht->size = 0;
	ft_ht_cpy(ht, old_arr, old_size);
	ft_memdel((void **)&old_arr);
}

void		ft_ht_decrease_arr_size(t_hash_table *ht)
{
	t_ht_elem	*old_arr;
	double		old_size;

	old_arr = ht->arr;
	old_size = ht->ht_size;
	ht->ht_size = ht->ht_size / 2;
	ht->arr = ft_memalloc(sizeof(t_ht_elem) * ht->ht_size);
	ht->size = 0;
	ft_ht_cpy(ht, old_arr, old_size);
	ft_memdel((void **)&old_arr);
}
