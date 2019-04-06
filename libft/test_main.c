#include "libft.h"
#include "ft_printf.h"
#include "ft_containers.h"
#include <time.h>

#define ITER_SIZE 27
#define HT_SIZE 81

size_t a[27] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 23, 24, 25, 26, 27};

int main2(void)
{
	srand(time(NULL));
	size_t i = -1;
	size_t rand_number;
	while (++i < ITER_SIZE)
	{
		rand_number = rand() % 10000000;
		ft_printf("(%zu) ", rand_number);
		ft_printf("[%zu]\n", ft_hthash(&rand_number, sizeof(size_t), HT_SIZE));
	}
	return (0);
}

int main(void)
{
	main2();
	system("leaks -q test");
	return (0);
}
