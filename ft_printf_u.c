/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:39:15 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 17:28:30 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char		*get_base(int par[9])
{
	if (par[8] == 'd' || par[8] == 'i' || par[8] == 'u'
			|| par[8] == 'U')
		return (ft_strdup("0123456789"));
	if (par[8] == 'p' || par[8] == 'x')
		return (ft_strdup("0123456789abcdef"));
	if (par[8] == 'o' || par[8] == 'O')
		return (ft_strdup("01234567"));
	if (par[8] == 'X')
		return (ft_strdup("0123456789ABCDEF"));
	return (NULL);
}

int			check_hash(char *str, int par[9])
{
	free(str);
	if (par[4] != -1)
	{
		if (par[8] == 'o' || par[8] == 'O')
		{
			str = ft_strdup("0");
			return (1);
		}
		if (par[8] == 'x')
		{
			str = ft_strdup("0x");
			return (2);
		}
		if (par[8] == 'X')
		{
			str = ft_strdup("0X");
			return (2);
		}
	}
	str = ft_strdup("");
	return (0);
}

int			ft_putnbr_uw(va_list *ap, int par[9])
{
	int					len;
	unsigned long long	arg;
	char				*base;
	char				*pref;

	base = get_base(par);
	pref = ft_strdup("");
	arg = get_nbr_by_bytes_u((size_t)va_arg(*ap, size_t), par[7]);
	len = ft_nbrlen_base_u(arg, base) + (arg == 0 ? 0 : check_hash(pref, par));
	if (arg == 0 && par[6] == -1 && !(par[8] == 'o' && par[4] == 1))
		return (ft_printf("%*s", par[5], ""));
	while (par[5] > len && par[5] > par[6] && par[3] == -1 &&
			par[0] == -1 && len++)
		ft_putchar(' ');
	ft_putstr(pref);
	while ((par[0] == -1 || len < par[6]) && (len < par[6] ||
				(par[3] != -1 && par[5] > len)) && ++len)
		ft_putchar('0');
	free(pref);
	ft_putnbr_base_fu(arg, base);
	free(base);
	while (par[0] != -1 && len < par[5] && ++len)
		ft_putchar(' ');
	return (len > par[5] ? len : par[5]);
}
