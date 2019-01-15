/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:47:02 by fratke            #+#    #+#             */
/*   Updated: 2019/01/15 22:40:08 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		(*g_f[]) (va_list *ap, int par[10]) = {ft_putstr_w, ft_putchar_w,
	ft_putptr_w, ft_putnbr_w, ft_putnbr_uw, ft_putfloat_w, ft_putfile_w,
	ft_puttab_w, ft_putfloat_e, ft_putfloat_g};

int		get_func_index(int par[10])
{
	if (par[8] == 's' || par[8] == 'S')
		return (0);
	if (par[8] == 'c' || par[8] == 'C')
		return (1);
	if (par[8] == 'p')
		return (2);
	if (par[8] == 'd' || par[8] == 'i' || par[8] == 'D')
		return (3);
	if (par[8] == 'o' || par[8] == 'u' || par[8] == 'O' ||
			par[8] == 'b' || par[8] == 'x' || par[8] == 'X')
		return (4);
	if (par[8] == 'U' && (par[7] = 64))
		return (4);
	if (par[8] == 'f' || par[8] == 'F')
		return (5);
	if (par[8] == 'w')
		return (6);
	if (par[8] == 'a')
		return (7);
	if (par[8] == 'e')
		return (8);
	if (par[8] == 'g')
		return (9);
	return (-1);
}

int		ft_putdefault(char **fmt, int par[9])
{
	int		i;
	int		ret;

	i = 0;
	while (fmt[0][i] != 0 && fmt[0][i + 1] != '%')
		i++;
	if (ft_isalpha(fmt[0][i]) && !i)
		i++;
	if (par[0] == -1)
	{
		if (par[3] == -1)
			ret = ft_printf("%*.*s", par[5], i, *fmt);
		else
			ret = ft_printf("%0*.*s", par[5], i, *fmt);
	}
	else if (par[3] == -1)
		ret = ft_printf("%-*.*s", par[5], i, *fmt);
	else
		ret = ft_printf("%-0*.*s", par[5], i, *fmt);
	if (fmt[0][i] == '%')
		i--;
	*fmt += i;
	return (ret);
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
		if (*fmt == '{')
			colors(&fmt);
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
