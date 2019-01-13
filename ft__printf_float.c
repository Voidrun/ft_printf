/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:41:37 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:43:22 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char		*get_right(double f, int prec)
{
	int		i;
	char	*res;

	if (f < 0)
		f = -f;
	i = 0;
	res = (char*)malloc(sizeof(char) * (prec + 3));
	if (prec != -1 && ++i && ++prec)
		res[0] = '.';
	if (res)
	{
		while (i < prec)
		{
			f -= (int)f;
			f *= 10;
			res[i] = (int)f + '0';
			i++;
		}
		res[i] = '\0';
		if (f * 10 > 40)
			res[i - 1] = (res[i - 1] == '9' ? '0' : res[i - 1] + 1);
	}
	return (res);
}

int			ft_putfloat_w(va_list *ap, int par[9])
{
	long long	left;
	char		*right;
	double		arg;
	int			len;

	if (par[6] == 0)
		par[6] = 6;
	arg = (float)va_arg(*ap, double);
	left = (long long)arg;
	right = get_right(arg, par[6]);
	len = ft_nbrlen_base(left, "0123456789") + ft_strlen(right);
	if (par[1] != -1 && left > 0 && ++len)
		ft_putchar('+');
	while (len < par[5] && par[0] == -1)
	{
		ft_putchar((par[3] == -1 ? ' ' : '0'));
		len++;
	}
	ft_printf("%lld%s", left, right);
	while (len < par[5] && par[0] == 1 && len++)
		ft_putchar(' ');
	free(right);
	return (len);
}
