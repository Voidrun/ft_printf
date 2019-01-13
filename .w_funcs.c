/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:34:26 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:28:34 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_putstr_w(va_list *ap, int par[9])
{
	int ret;
	if (par[7] == 64)
		ret = (ft_putstr_fw((wchar_t*)va_arg(*ap, wchar_t*), par));
	else
		ret = (ft_putstr_f((char*)va_arg(*ap, char*), par));
	return (ret > par[5] ? ret : par[5]);
}

int		ft_putchar_w(va_list *ap, int par[9])
{
	int	ret;
	ret = (ft_putchar_f((char)va_arg(*ap, int), par));
	return (ret > par[5] ? ret : par[5]);
}

int		ft_putptr_w(va_list *ap, int par[9])
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

char 	*get_base(int par[9])
{
	if (par[8] == 'd' || par[8] == 'i' || par[8] == 'u'
			|| par[8] == 'U')
		return (ft_strdup("0123456789"));
	if (par[8] == 'p' || par[8] == 'x')
		return (ft_strdup("0123456789abcdef"));
	if (par[8] == 'o')
		return (ft_strdup("01234567"));
	if (par[8] == 'X')
		return (ft_strdup("0123456789ABCDEF"));
	return (NULL);
}

int		check_hash(char *str, int par[9])
{
	free(str);
	if (par[4] != -1)
	{
		if (par[8] == 'o')
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

int		ft_putnbr_uw(va_list *ap, int par[9])
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
	while (par[5] > len && par[5] > par[6] && par[3] == -1 && par[0] == -1)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putstr(pref);
	while ((par[0] == -1 || len < par[6]) && (len < par[6] || (par[3] != -1 && par[5] > len)) && ++len)
		ft_putchar('0');
	free(pref);
	ft_putnbr_base_fu(arg, base);
	free(base);
	while (par[0] != -1 && len < par[5] && ++len)
		ft_putchar(' ');
	return (len > par[5] ? len : par[5]);
}

char		*get_width(int len, int par[9])
{
	char	*res;
	int		i;
	int		diff;

	diff = par[5] - len;
	if (diff > 0)
	{
		res = (char*)malloc(sizeof(char) * (diff + 1));
		i = 0;
		while (i < diff)
		{
			res[i] = (par[0] == -1 && par[3] == 1 ? '0' : ' ');
			if (par[6] < par[5] && par[3] == 1 && par[0] == -1
					&& par[6] != 0)
				res[i] = ' ';
			i++;
		}
		res[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (res);
}


char		*get_prec(int len, int par[9])
{
	char	*res;
	int		i;
	int		diff;

	diff = par[6] - len;
	if (diff > 0)
	{
		res = (char*)malloc(sizeof(char) * (diff + 1));
		i = 0;
		while (i < diff)
		{
			res[i] = '0';
			i++;
		}
		res[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (res);
}

char		*get_sign(char **nstr, int par[9])
{
	par[4] = 0;
	if (par[1] == 1 && *nstr[0] != '-')
		return (ft_strdup("+"));
	if (par[2] == 1 && *nstr[0] != '-')
		return (ft_strdup(" "));
	if (*nstr[0] == '-')
	{
		par[4] = 1;
		(*nstr)++;
		return (ft_strdup("-"));
	}
	return (ft_strdup(""));
}

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
		par[8] = ft_printf("%s%s%s%s", sign, width, prec,  nstr);
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
		par[8] = ft_printf("%s%s%s%s", sign, width, prec,  nstr);
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
		par[8] = ft_printf("%s%s%s%s", sign, width, prec,  nstr);
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
		par[8] = ft_printf("%s%s%s%s", sign, width, prec,  nstr);
	else
		par[8] = ft_printf("%s%s%s%s", width, sign, prec, nstr);
	free(width);
	free(sign);
	free(prec);
	free(nstr - par[4]);
	return (par[8]);
}


int		ft_putnbr_w(va_list *ap, int par[9])
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

char	*get_right(double f, int prec)
{
	int		i;
	char	*res;

	if (f < 0)
		f = -f;
	i = 0;
	res = (char*)malloc(sizeof(char) * (prec + 3));
	if (prec != - 1 && ++i && ++prec)
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

int		ft_putfloat_w(va_list *ap, int par[9])
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
	while (len < par[5] && par[0] == 1)
	{
		ft_putchar(' ');
		len++;
	}
	free(right);
	return (len);
}
