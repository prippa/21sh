#include "ft_mem.h"

void	ft_cnt_delptr(void *ptr, size_t ptr_size)
{
	(void)ptr_size;
	ft_memdel(&ptr);
}
