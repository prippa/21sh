#include "libft.h"
#include "ft_printf.h"

void	sh_lstpush_back(t_list *lst, t_bool make_copy_of_content,
			void *content, size_t content_size)
{
	t_list_elem *new_obj;

	if (make_copy_of_content)
	{
		if (!(new_obj = ft_lstnew(content, content_size)))
			ft_perror_exit("malloc");
	}
	else
	{
		if (!(new_obj = ft_memalloc(sizeof(t_list_elem))))
			ft_perror_exit("malloc");
		new_obj->content = content;
		new_obj->content_size = content_size;
	}
	ft_lstpush_back(lst, new_obj);
}

void	sh_lstpush_front(t_list *lst, t_bool make_copy_of_content,
			void *content, size_t content_size)
{
	t_list_elem *new_obj;

	if (make_copy_of_content)
	{
		if (!(new_obj = ft_lstnew(content, content_size)))
			ft_perror_exit("malloc");
	}
	else
	{
		if (!(new_obj = ft_memalloc(sizeof(t_list_elem))))
			ft_perror_exit("malloc");
		new_obj->content = content;
		new_obj->content_size = content_size;
	}
	ft_lstpush_front(lst, new_obj);
}

#define ELEM_1 "Lol"
#define ELEM_2 "Hello world!"
#define ELEM_3 "42"

void	print_list(t_list_elem *elem)
{
	char	*n;

	n = elem->content;
	ft_printf("%s\n", n);
}

int main2(void)
{
	t_list lst;

	ft_bzero(&lst, sizeof(t_list));
	// if (!(lst = ft_memalloc(sizeof(t_list))))
	// 	ft_perror_exit("malloc");
	sh_lstpush_back(&lst, true, ELEM_1, ft_strlen(ELEM_1));
	sh_lstpush_back(&lst, true, ELEM_2, ft_strlen(ELEM_2));
	sh_lstpush_front(&lst, true, ELEM_3, ft_strlen(ELEM_3));
	ft_lstiter(lst.start, &print_list);
	ft_putchar('\n');
	ft_lstrev(&lst);
	ft_lstiter(lst.start, &print_list);
	ft_putchar('\n');

	ft_lstdel_by_obj(&lst, lst.start, &ft_lstdel_content);
	ft_lstdel_by_obj(&lst, lst.start, &ft_lstdel_content);
	ft_lstdel_by_obj(&lst, lst.start, &ft_lstdel_content);
	ft_lstpop_front(&lst, ft_lstdel_content);
	ft_lstpop_front(&lst, ft_lstdel_content);
	ft_lstpop_front(&lst, ft_lstdel_content);
	ft_lstpop_front(&lst, ft_lstdel_content);
	ft_lstpop_front(&lst, ft_lstdel_content);
	ft_lstpop_back(&lst, ft_lstdel_content);
	ft_lstpop_back(&lst, ft_lstdel_content);
	ft_lstpop_back(&lst, ft_lstdel_content);
	ft_lstpop_back(&lst, ft_lstdel_content);
	ft_printf("list_size (%zu)\n", lst.list_size);
	ft_lstiter(lst.start, &print_list);

	// if (lst.start)
	// 	ft_printf("\nYEAS1!%s!\n", (char *)lst.start->content);
	// ft_lstdel_by_obj(&lst, lst.start, ft_lstdel_content);
	// if (lst.start)
	// 	ft_printf("\nYEAS2!%s!\n", (char *)lst.start->content);
	// ft_printf("list_size (%zu)\n", lst.list_size);
	// ft_lstiter(lst.start, &print_list);
	ft_lstdel(&lst, &ft_lstdel_content);
	return (0);
}

int main(void)
{
	main2();
	system("leaks -q lst");
	return (0);
}
