#include "libft/includes/libc/libft.h"
#include "libft/includes/printf/ft_printf.h"

int main(void)
{
	char		*dst = ft_strdup("left");
	const char	*src = "right";

	ft_printf("[%s]\n", dst);

	ft_strinsert_free(&dst, src, ft_strlen(dst));
	ft_printf("[%s]\n", dst);

	ft_strinsert_free(&dst, " mid ", 4);
	ft_printf("[%s]\n", dst);

	system("leaks -q a.out");
	return (0);
}