/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eg_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:54:29 by fratke            #+#    #+#             */
/*   Updated: 2019/01/15 23:07:16 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_putfloat_gl(va_list *ap, int par[9])
{
	int			e;
	long double	f;
	long double	t;

	e = 0;
	par[6] = (par[6]) ? (par[6]) : (5);
	f = (long double)va_arg(*ap, long double);
	t = f;
	if (f < 1 && f > -1)
	{
		while (((f > 0 && f < 1) || (f < 0 && f > -1)) && (f *= 10))
			e++;
		if (e > 4 || e >= par[6])
			return (ft_printf("%*.*Lfe-%02d", par[5] - 4, par[6], f, e));
		else
			return (ft_printf("%*.*Lf", par[5], par[6], t));
	}
	while (((f > 0 && f > 10) || (f < 0 && f < -10)) && (f /= 10))
		e++;
	if (e > 4 || e >= par[6])
		return (ft_printf("%*.*Lfe+%02d", par[5] - 4, par[6], f, e));
	else
		return (ft_printf("%*.*Lf", par[5], par[6], t));
}

int		ft_putfloat_el(va_list *ap, int par[9])
{
	int			e;
	long double	f;

	e = 0;
	par[6] = (par[6]) ? (par[6]) : (6);
	f = (long double)va_arg(*ap, long double);
	if (f < 1 && f > -1)
	{
		while (((f > 0 && f < 1) || (f < 0 && f > -1)) && (f *= 10))
			e++;
		return (ft_printf("%*.*Lfe-%02d", par[5] - 4, par[6], f, e));
	}
	else
	{
		while (((f > 0 && f > 10) || (f < 0 && f < -10)) && (f /= 10))
			e++;
		return (ft_printf("%*.*Lfe+%02d", par[5] - 4, par[6], f, e));
	}
}

int		ft_putfloat_g(va_list *ap, int par[9])
{
	int		e;
	double	f;
	double	t;

	if (par[7] == 64)
		return (ft_putfloat_gl(ap, par));
	e = 0;
	par[6] = (par[6]) ? (par[6]) : (5);
	f = (double)va_arg(*ap, double);
	t = f;
	if (f < 1 && f > -1)
	{
		while (((f > 0 && f < 1) || (f < 0 && f > -1)) && (f *= 10))
			e++;
		if (e > 4 || e >= par[6])
			return (ft_printf("%*.*fe-%02d", par[5] - 4, par[6], f, e));
		else
			return (ft_printf("%*.*f", par[5], par[6], t));
	}
	while (((f > 0 && f > 10) || (f < 0 && f < -10)) && (f /= 10))
		e++;
	if (e > 4 || e >= par[6])
		return (ft_printf("%*.*fe+%02d", par[5] - 4, par[6], f, e));
	else
		return (ft_printf("%*.*f", par[5], par[6], t));
}

int		ft_putfloat_e(va_list *ap, int par[9])
{
	int		e;
	double	f;

	if (par[7] == 64)
		return (ft_putfloat_el(ap, par));
	e = 0;
	par[6] = (par[6]) ? (par[6]) : (6);
	f = (double)va_arg(*ap, double);
	if (f < 1 && f > -1)
	{
		while (((f > 0 && f < 1) || (f < 0 && f > -1)) && (f *= 10))
			e++;
		return (ft_printf("%*.*fe-%02d", par[5] - 4, par[6], f, e));
	}
	else
	{
		while (((f > 0 && f > 10) || (f < 0 && f < -10)) && (f /= 10))
			e++;
		return (ft_printf("%*.*fe+%02d", par[5] - 4, par[6], f, e));
	}
}
