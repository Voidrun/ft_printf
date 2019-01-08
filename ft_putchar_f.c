#include "libft/libft.h"

int		ft_putchar_f(char c, int params[9])
{
	int	i;

	i = 0;
	if (params[0] == -1)
	{
		while (i < params[5] - 1)
		{
			ft_putchar(params[3] == -1 ? ' ' : '0');
			i++;
		}
	}
	ft_putchar(c);
	if (params[0] != -1)
	{
		while (i < params[5] - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (1);
}