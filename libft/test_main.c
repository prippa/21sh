#include "libft.h"
#include "ft_printf.h"
#include "ft_containers.h"
#include <time.h>
#include <stdio.h>

#define ITER_SIZE 27
#define HT_SIZE 81
size_t a[ITER_SIZE] = {127, 2117294875, 10, 4741915, 4610843, 9, 4479771, 4414235,
4283163, 4348699, 74995417045787, 73895905418011, 71696882162459, 72796393790235,
74999712013083, 73900200385307, 71701177129755, 72800688757531, 4, 1, 5,
7, 21, 11, 8, 12, 18};

#define STR1 "Hello 42"
#define STR2 "Hello 43"
#define STR3 "Hello 44"
#define STR4 "Hello 45"
#define STR5 "Hello 46"
#define STR6 "Hello 47"

void print_ht(t_ht_elem *elem)
{
	ft_printf("\n---------------\n");
	if (elem->key)
		ft_printf("key   = [%zu]\n", *(size_t *)elem->key);
	else
		ft_printf("key   = [NULL]\n");
	if (elem->value)
	{
		ft_putstr("value = [");
		write(STDOUT_FILENO, elem->value, elem->value_size);
		ft_putstr("]\n");
	}
	else
		ft_printf("value = [NULL]\n");
	ft_printf("---------------\n");
}

void print_lst(t_list_elem *elem)
{
	printf("i - %u\n", *(uint32_t *)elem->content);
}

t_bool if_in(t_list_elem *start, uint32_t n)
{
	while (start)
	{
		if (n == *(uint32_t *)start->content)
			return (true);
		start = start->next;
	}
	return (false);
}

int main2(void)
{
	t_hash_table	ht;
	uint32_t		i;
	uint32_t		n;
	t_list			l;
	t_list			hs;

	LST_INIT(&l, &ft_cnt_delptr);
	LST_INIT(&hs, &ft_cnt_delptr);
	srand(time(NULL));
	ft_htinit(&ht, 100, &ft_cnt_delptr, &ft_cnt_delptr);
	printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	i = -1;
	while (++i < 27)
	{
		n = ft_ht_hash((size_t[]){rand() % 783442654}, 8, 67);
		if (if_in(hs.start, n))
			LST_PUSH_BACK(&l, &i, 4);
		printf("i: %u (hash - [%u])\n", i, n);
		LST_PUSH_BACK(&hs, &n, 4);
		// HT_INSERT(&ht, (size_t[]){rand() % 783442654}, NULL, sizeof(size_t), 0);
	}
	printf("\n");
	ft_lstiter(&l, &print_lst);
	printf("\n");
	// printf("\nht_size - $%f$\n", ht.ht_size);
	// printf("\nsize - $%u$\n", ht.size);
	// printf("\ncoalitions - $%u$\n", ht.coalitions);
	// t_ht_elem *e;
	// i = -1;
	// while (++i < ITER_SIZE)
	// {
	// 	e = ft_htget(&ht, &a[i], sizeof(size_t));
	// 	printf("\n");
	// }
	// ft_htiter_all(&ht, &print_ht);
	// printf("\n===================================\n");
	// ft_htiter_exist(&ht, &print_ht);
	// ft_htinsert(&ht, HT_ELEM((int[]){44124}, STR5, sizeof(int32_t), ft_strlen(STR5)));
	// ft_htinsert(&ht, HT_ELEM((int[]){812347}, STR2, sizeof(int32_t), ft_strlen(STR2)));
	// ft_htinsert(&ht, HT_ELEM((int[]){2}, STR1, sizeof(int32_t), ft_strlen(STR1)));
	// ft_htinsert(&ht, HT_ELEM((int[]){1242}, STR4, sizeof(int32_t), ft_strlen(STR4)));
	// // printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// // ft_htinsert(&ht, HT_ELEM((int[]){42}, "LOLOLOLOLOLO", sizeof(int32_t), ft_strlen("LOLOLOLOLOLO")));
	// ft_htinsert(&ht, HT_ELEM((int[]){987345}, STR6, sizeof(int32_t), ft_strlen(STR6)));
	// ft_htinsert(&ht, HT_ELEM((int[]){20}, STR3, sizeof(int32_t), ft_strlen(STR3)));
	// ft_htiter_all(&ht, &print_ht);

	// t_ht_elem *e;

	// e = ft_htget(&ht, (int[]){44124}, sizeof(int32_t));
	// print_ht(e);
	// e = ft_htget(&ht, (int[]){812347}, sizeof(int32_t));
	// print_ht(e);
	// e = ft_htget(&ht, (int[]){2}, sizeof(int32_t));
	// print_ht(e);
	// e = ft_htget(&ht, (int[]){1242}, sizeof(int32_t));
	// print_ht(e);
	// e = ft_htget(&ht, (int[]){987345}, sizeof(int32_t));
	// print_ht(e);
	// e = ft_htget(&ht, (int[]){20}, sizeof(int32_t));
	// print_ht(e);
	// ft_htremove(&ht, (int[]){44}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htremove(&ht, (int[]){46}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htremove(&ht, (int[]){45}, 4);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htremove(&ht, (int[]){43}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	HT_DEL(&ht);
	LST_DEL(&l);
	LST_DEL(&hs);
	return (0);
}

int main(void)
{
	main2();
	system("leaks -q test");
	return (0);
}
