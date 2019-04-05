#include "ft_hash_table.h"
#include "ft_mem.h"

t_hash_table	tf_htinit(size_t size)
{
	t_hash_table ht;

	(void)size;
	ft_bzero(&ht, sizeof(t_hash_table));
	return (ht);
}
