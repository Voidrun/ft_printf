/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:42:12 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:42:36 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putstr_w(va_list *ap, int par[9])
{
	int ret;

	if (par[7] == 64)
		ret = (ft_putstr_fw((wchar_t*)va_arg(*ap, wchar_t*), par));
	else
		ret = (ft_putstr_f((char*)va_arg(*ap, char*), par));
	return (ret > par[5] ? ret : par[5]);
}

int			ft_putchar_w(va_list *ap, int par[9])
{
	int	ret;

	ret = (ft_putchar_f((char)va_arg(*ap, int), par));
	return (ret > par[5] ? ret : par[5]);
}

int			ft_putptr_w(va_list *ap, int par[9])
{
	size_t	arg;
	int		len;

	arg = (size_t)va_arg(*ap, size_t);
	len = ft_nbrlen_base(arg, "0123456789abcdef") + 2;
	while (par[0] == -1 && len < par[5])
	{
		len++;
		ft_putchar(' ');
	}
	ft_putstr("0x");
	ft_putnbr_base_f(arg, "0123456789abcdef");
	while (par[0] == 1 && len < par[5])
	{
		len++;
		ft_putchar(' ');
	}
	return (len);
}
