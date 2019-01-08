#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putstr_f(char *str, int params[9])
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (params[0] != -1)
	{
		while (str[++i] && (i < params[6] || !params[6]))
			ft_putchar(str[i]);
		while (i++ < params[5])
			ft_putchar(' ');
	}
	else
	{
		while (i < params[5] - len - 1)
		{
			ft_putchar(' ');
			i++;
		}
		i = -1;
		while (str[++i] && (i < params[6] || !params[6]))
			ft_putchar(str[i]);
	}
	return (i);
}