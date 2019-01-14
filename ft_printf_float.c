/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__printf_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:41:37 by fratke            #+#    #+#             */
/*   Updated: 2019/01/14 23:25:59 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		fround(char *res)
{
	int		i;
	int		j;

	i = ft_strlen(res) - 1;
	while (i > 0)
	{
		j = i;
		while (res[j] == '9')
		{
			res[j] = '0';
			res[j - 1] = (res[j - 1] == '9') ? ('9') : (res[j - 1] + 1);
			j--;
		}
		i--;
	}
}

char		*get_right_l(long double f, int prec)
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
			f -= (long long)f;
			f *= 10;
			res[i] = (long long)f + '0';
			i++;
		}
		f -= (long long)f;
		res[i] = '\0';
		res[i - 1] = (f * 10 > 4) ? (res[i] + 1) : (res[i] - 1);
	}
	fround(res);
	return (res);
}

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
			f -= (long long)f;
			f *= 10;
			res[i] = (long long)f + '0';
			i++;
		}
		res[i] = '\0';
	}
	fround(res);
	return (res);
}

int			ft_putfloat_wl(va_list *ap, int par[9])
{
	long long		left;
	char			*right;
	double			arg;
	int				len;

	if (par[6] == 0)
		par[6] = 6;
	arg = (long double)va_arg(*ap, long double);
	left = (long long)arg;
	right = get_right_l(arg, par[6]);
	len = ft_nbrlen_base(left, "0123456789") + ft_strlen(right);
	if (par[1] != -1 && left > 0 && ++len)
		ft_putchar('+');
	while (len < par[5] && par[0] == -1 && len++)
		ft_putchar((par[3] == -1 ? ' ' : '0'));
	ft_printf("%lld%s", left, right);
	while (len < par[5] && par[0] == 1 && len++)
		ft_putchar(' ');
	free(right);
	return (len);
}

int			ft_putfloat_w(va_list *ap, int par[9])
{
	long long		left;
	char			*right;
	double			arg;
	int				len;

	if (par[6] == 0)
		par[6] = 6;
	if (par[7] == 64)
		return (ft_putfloat_wl(ap, par));
	arg = (double)va_arg(*ap, double);
	left = (long long)arg;
	right = get_right(arg, par[6]);
	len = ft_nbrlen_base(left, "0123456789") + ft_strlen(right);
	if (par[1] != -1 && left > 0 && ++len)
		ft_putchar('+');
	while (len < par[5] && par[0] == -1 && len++)
		ft_putchar((par[3] == -1 ? ' ' : '0'));
	ft_printf("%lld%s", left, right);
	while (len < par[5] && par[0] == 1 && len++)
		ft_putchar(' ');
	free(right);
	return (len);
}
