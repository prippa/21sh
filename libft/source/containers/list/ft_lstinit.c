#include "ft_list.h"
#include "ft_mem.h"

void	ft_lstinit(t_list *lst, t_delptr del_list_func)
{
	ft_bzero(lst, sizeof(t_list));
	lst->del = del_list_func;
}
