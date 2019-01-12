#include "ft_printf.h"
#include "./libft/libft.h"

int		(*g_f[]) (va_list *ap, int par[10]) = {ft_putstr_w, ft_putchar_w, ft_putptr_w,
								ft_putnbr_w, ft_putnbr_uw, ft_putfloat_w};

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

void	set_flags(char **fmt, int flags[10])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		flags[i] = -1;
		i++;
	}
	i = 0;
	while (ft_strchr("-+ 0#", **fmt))
	{
		if (*fmt[i] == '-')
			flags[0] = 1;
		if (*fmt[i] == '+')
			flags[1] = 1;
		if (*fmt[i] == ' ')
			flags[2] = 1;
		if (*fmt[i] == '0')
			flags[3] = 1;
		if (*fmt[i] == '#')
			flags[4] = 1;
		(*fmt)++;
	}
}

void	*get_arg(int n, va_list ap)
{
	int		i;
	va_list	aq;
	void	*ret;

	i = 1;
	va_copy(aq, ap);
	while (i < n)
	{
		ret = va_arg(aq, void*);
		i++;
	}
	ret = va_arg(aq, void*);
	va_end(aq);
	return (ret);
}

void	parse_format(char **fmt, int par[10], va_list *ap)
{
	set_flags(fmt, par);
	par[5] = (**fmt == '*' ? va_arg(*ap, int) : ft_atoi(*fmt));
	if (**fmt == '*')
		(*fmt)++;
	while (ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '.')
		(*fmt)++;
	par[6] = (**fmt == '*' ? va_arg(*ap, int) : ft_atoi(*fmt));
	if (**fmt == '0' || (*((*fmt) - 1) == '.' && par[6] == 0))
		par[6] = -1;
	while (ft_isdigit(**fmt) || **fmt == '*')
		(*fmt)++;
	par[7] = 32;
	if (**fmt == 'h' && (*fmt)++)
	{
		par[7] = 16;
		if (**fmt == 'h' && (*fmt)++)
			par[7] = 8;
	}
	else if ((**fmt == 'l' || **fmt == 'j' || **fmt == 'z') && (*fmt)++)
	{
		par[7] = 64;
		if (**fmt == 'l' && (*fmt)++)
			par[7] = 64;
	}
	par[8] = (int)**fmt;
}

int		dispatcher(char **fmt, va_list *ap)
{
	int		par[10];
	int		i;

	parse_format(fmt, par, ap);
	i = get_func_index(par);
	if (i == -1)
	{
		i = (par[0] == -1 ? ft_printf("%*s", par[5], *fmt) : ft_printf("%-*s", par[5], *fmt));
		return (i);
	}
	return (g_f[i] (ap, par));
}

int		ft_printf(char *fmt, ...)
{
	int		count;
	va_list ap;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && fmt++ && *fmt != 0  && *fmt != '%')
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
