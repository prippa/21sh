#ifndef FT_CNT_GENERAL_H
# define FT_CNT_GENERAL_H

# include <stddef.h>

typedef void	(*t_delptr)(void *ptr, size_t ptr_size);

void	ft_cnt_delptr(void *ptr, size_t ptr_size);

#endif
