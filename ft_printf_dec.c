/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:37:20 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:43:48 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putnbr_wl(va_list *ap, int par[9])
{
	char	*nstr;
	char	*prec;
	char	*width;
	char	*sign;

	nstr = ft_itoa_l((long long)va_arg(*ap, long long));
	if (!ft_strcmp(nstr, "0") && par[6] == -1)
	{
		free(nstr);
		nstr = ft_strdup("");
	}
	sign = get_sign(&nstr, par);
	prec = get_prec(ft_strlen(nstr), par);
	width = get_width(ft_strlen(nstr) + ft_strlen(prec) + ft_strlen(sign), par);
	if (par[0] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, prec, nstr, width);
	else if (par[3] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, width, prec, nstr);
	else
		par[8] = ft_printf("%s%s%s%s", width, sign, prec, nstr);
	free(width);
	free(sign);
	free(prec);
	free(nstr - par[4]);
	return (par[8]);
}

int			ft_putnbr_wh(va_list *ap, int par[9])
{
	char	*nstr;
	char	*prec;
	char	*width;
	char	*sign;

	nstr = ft_itoa((short)va_arg(*ap, int));
	if (!ft_strcmp(nstr, "0") && par[6] == -1)
	{
		free(nstr);
		nstr = ft_strdup("");
	}
	sign = get_sign(&nstr, par);
	prec = get_prec(ft_strlen(nstr), par);
	width = get_width(ft_strlen(nstr) + ft_strlen(prec) + ft_strlen(sign), par);
	if (par[0] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, prec, nstr, width);
	else if (par[3] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, width, prec, nstr);
	else
		par[8] = ft_printf("%s%s%s%s", width, sign, prec, nstr);
	free(width);
	free(sign);
	free(prec);
	free(nstr - par[4]);
	return (par[8]);
}

int			ft_putnbr_whh(va_list *ap, int par[9])
{
	char	*nstr;
	char	*prec;
	char	*width;
	char	*sign;

	nstr = ft_itoa((char)va_arg(*ap, int));
	if (!ft_strcmp(nstr, "0") && par[6] == -1)
	{
		free(nstr);
		nstr = ft_strdup("");
	}
	sign = get_sign(&nstr, par);
	prec = get_prec(ft_strlen(nstr), par);
	width = get_width(ft_strlen(nstr) + ft_strlen(prec) + ft_strlen(sign), par);
	if (par[0] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, prec, nstr, width);
	else if (par[3] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, width, prec, nstr);
	else
		par[8] = ft_printf("%s%s%s%s", width, sign, prec, nstr);
	free(width);
	free(sign);
	free(prec);
	free(nstr - par[4]);
	return (par[8]);
}

int			ft_putnbr_wd(va_list *ap, int par[9])
{
	char	*nstr;
	char	*prec;
	char	*width;
	char	*sign;

	nstr = ft_itoa((int)va_arg(*ap, int));
	if (!ft_strcmp(nstr, "0") && par[6] == -1)
	{
		free(nstr);
		nstr = ft_strdup("");
	}
	sign = get_sign(&nstr, par);
	prec = get_prec(ft_strlen(nstr), par);
	width = get_width(ft_strlen(nstr) + ft_strlen(prec) + ft_strlen(sign), par);
	if (par[0] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, prec, nstr, width);
	else if (par[3] == 1)
		par[8] = ft_printf("%s%s%s%s", sign, width, prec, nstr);
	else
		par[8] = ft_printf("%s%s%s%s", width, sign, prec, nstr);
	free(width);
	free(sign);
	free(prec);
	free(nstr - par[4]);
	return (par[8]);
}

int			ft_putnbr_w(va_list *ap, int par[9])
{
	if (par[7] == 32)
		return (ft_putnbr_wd(ap, par));
	if (par[7] == 64)
		return (ft_putnbr_wl(ap, par));
	if (par[7] == 16)
		return (ft_putnbr_wh(ap, par));
	if (par[7] == 8)
		return (ft_putnbr_whh(ap, par));
	return (-1);
}
