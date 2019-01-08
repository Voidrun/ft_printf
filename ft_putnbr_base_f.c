#include "ft_printf.h"
#include "libft/libft.h"

long long int	check_neg(long long int nbr)
{
	long long int temp;

	temp = nbr;
	if (temp < 0)
	{
		return (-temp);
	}
	return (temp);
}

int				ft_putnbr_base_f(long long int nbr, char *base)
{
	long long int len;
	long long int divider;
	long long int temp;

	if (nbr == 0)
		ft_putchar('0');
	len = 0;
	divider = 1;
	temp = check_neg(nbr);
	while (base[len] != '\0')
		len++;
	while (nbr != 0)
	{
		divider = divider * len;
		nbr = nbr / len;
	}
	divider = divider / len;
	while (divider > 0)
	{
		ft_putchar(base[(temp / divider) % len]);
		divider = divider / len;
	}
	return (len);
}