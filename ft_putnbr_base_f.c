/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:53:45 by fratke            #+#    #+#             */
/*   Updated: 2019/01/14 22:24:11 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				edge_case(long long nbr, char *base)
{
	if (nbr < -9223372036854775807)
	{
		if (!ft_strcmp(base, "0123456789"))
			return (ft_printf("-9223372036854775808"));
		if (!ft_strcmp(base, "0123456789abcdef") ||
				!ft_strcmp(base, "0123456789ABCDEF"))
			return (ft_printf("-8000000000000000"));
		if (!ft_strcmp(base, "01234567"))
			return (ft_printf("-1000000000000000000000"));
	}
	else
	{
		if (!ft_strcmp(base, "0123456789"))
			return (ft_printf("9223372036854775807"));
		if (!ft_strcmp(base, "0123456789abcdef") ||
				!ft_strcmp(base, "0123456789ABCDEF"))
			return (ft_printf("7FFFFFFFFFFFFFFF"));
		if (!ft_strcmp(base, "01234567"))
			return (ft_printf("777777777777777777777"));
	}
	return (0);
}

int				ft_putnbr_base_f(long long int nbr, char *base)
{
	long long int len;
	long long int divider;
	long long int temp;

	if (nbr == 9223372036854775807 || nbr < -9223372036854775807)
		return (edge_case(nbr, base));
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

int				ft_putnbr_base_fu(unsigned long long nbr, char *base)
{
	unsigned long long len;
	unsigned long long divider;
	unsigned long long temp;

	if (nbr == 0)
		return (ft_printf("0"));
	len = 0;
	divider = 1;
	temp = nbr;
	while (base[len] != '\0')
		len++;
	while (nbr > len)
	{
		divider = divider * len;
		nbr = nbr / len;
	}
	divider *= (divider * len == temp) ? (len) : (1);
	while (divider > 0)
	{
		ft_putchar(base[(temp / divider) % len]);
		divider = divider / len;
	}
	return (len);
}
