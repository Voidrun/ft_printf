/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:47:02 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:49:32 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		(*g_f[]) (va_list *ap, int par[10]) = {ft_putstr_w, ft_putchar_w,
	ft_putptr_w, ft_putnbr_w, ft_putnbr_uw, ft_putfloat_w};

int		get_func_index(int par[10])
{
	if (par[8] == 's')
		return (0);
	if (par[8] == 'S')
	{
		par[7] = 64;
		return (0);
	}
	if (par[8] == 'c')
		return (1);
	if (par[8] == 'p')
		return (2);
	if (par[8] == 'd' || par[8] == 'i')
		return (3);
	if (par[8] == 'o' || par[8] == 'u' || par[8] == 'x' || par[8] == 'X')
		return (4);
	if (par[8] == 'U')
	{
		par[7] = 64;
		return (4);
	}
	if (par[8] == 'f')
		return (5);
	return (-1);
}

int		ft_putdefault(char **fmt, int par[9])
{
	int		len;
	int		i;

	i = 0;
	while (fmt[0][i] != '%' && fmt[0][i] != 0)
		i++;
	if (fmt[0][i] != 0 && fmt[0][i + 1] == 0 && fmt[0][i] == '%'
			&& !ft_isalpha(fmt[0][i - 1]))
		i++;
	len = ft_strlen(*fmt);
	while (par[0] == -1 && len < par[5])
	{
		len++;
		ft_putchar((par[3] == -1) ? ' ' : '0');
	}
	if (par[5] == 0)
		len = ft_printf("%.*s", i, *fmt);
	else
		ft_printf("%s", *fmt);
	while (par[0] == 1 && len < par[5] && len++)
		ft_putchar(' ');
	while (**fmt && fmt[0][1] != '%')
		(*fmt)++;
	return (len);
}

int		dispatcher(char **fmt, va_list *ap)
{
	int		par[10];
	int		i;

	parse_format(fmt, par, ap);
	i = get_func_index(par);
	if (i == -1)
		return (ft_putdefault(fmt, par));
	return (g_f[i](ap, par));
}

int		ft_printf(char *fmt, ...)
{
	int		count;
	va_list ap;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && fmt++ && *fmt != 0 && *fmt != '%')
		{
			count += dispatcher(&fmt, &ap);
		}
		else if (*fmt)
		{
			ft_putchar(*fmt);
			count++;
		}
		if (*fmt)
			fmt++;
	}
	va_end(ap);
	return (count);
}
