#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	char *p = ft_strdup("string");

	int ret = printf("|% -20f|\n", 1.0);
	int ret2 = ft_printf("%#X\n", 123);
	printf("%d %d\n", ret, ret2);
}