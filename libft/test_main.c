#include "libft.h"
#include "ft_printf.h"
#include "ft_containers.h"
#include <time.h>
#include <stdio.h>

// #define ITER_SIZE 27
// #define HT_SIZE 81
// size_t a[27] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
// 21, 22, 23, 24, 25, 26, 27};

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
		ft_printf("key   = [%d]\n", *(int *)elem->key);
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

int main2(void)
{
	t_hash_table ht;

	ft_htinit(&ht, 0, &ft_cnt_delptr, &ft_cnt_delptr);
	HT_INSERT(&ht, (int[]){44124}, STR5, sizeof(int32_t), ft_strlen(STR5));
	ft_htinsert(&ht, HT_ELEM((int[]){44124}, STR5, sizeof(int32_t), ft_strlen(STR5)));
	ft_htinsert(&ht, HT_ELEM((int[]){812347}, STR2, sizeof(int32_t), ft_strlen(STR2)));
	ft_htinsert(&ht, HT_ELEM((int[]){2}, STR1, sizeof(int32_t), ft_strlen(STR1)));
	ft_htinsert(&ht, HT_ELEM((int[]){1242}, STR4, sizeof(int32_t), ft_strlen(STR4)));
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htinsert(&ht, HT_ELEM((int[]){42}, "LOLOLOLOLOLO", sizeof(int32_t), ft_strlen("LOLOLOLOLOLO")));
	ft_htinsert(&ht, HT_ELEM((int[]){987345}, STR6, sizeof(int32_t), ft_strlen(STR6)));
	ft_htinsert(&ht, HT_ELEM((int[]){20}, STR3, sizeof(int32_t), ft_strlen(STR3)));
	ft_htiter_all(&ht, &print_ht);
	printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);

	t_ht_elem *e;

	e = ft_htget(&ht, (int[]){44124}, sizeof(int32_t));
	print_ht(e);
	e = ft_htget(&ht, (int[]){812347}, sizeof(int32_t));
	print_ht(e);
	e = ft_htget(&ht, (int[]){2}, sizeof(int32_t));
	print_ht(e);
	e = ft_htget(&ht, (int[]){1242}, sizeof(int32_t));
	print_ht(e);
	e = ft_htget(&ht, (int[]){987345}, sizeof(int32_t));
	print_ht(e);
	e = ft_htget(&ht, (int[]){20}, sizeof(int32_t));
	print_ht(e);
	// ft_htremove(&ht, (int[]){44}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htremove(&ht, (int[]){46}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htremove(&ht, (int[]){45}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	// ft_htremove(&ht, (int[]){43}, 4);
	// ft_htiter_exist(&ht, &print_ht);
	// printf("\n$$$$$$$$$$$$$$$$$$$$$$%f$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n", ht.ht_size);
	ft_htdel(&ht);
	return (0);
}

int main(void)
{
	main2();
	system("leaks -q test");
	return (0);
}
