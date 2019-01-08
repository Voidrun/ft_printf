#include "ft_printf.h"
#include "libft/libft.h"

int		ft_putstr_w(va_list ap, int par[9])
{
	int ret;
	ret = (ft_putstr_f((char*)va_arg(ap, char*), par));
	return (ret > par[5] ? ret : par[5]);
}

int		ft_putchar_w(va_list ap, int par[9])
{
	int	ret;
	ret = (ft_putchar_f((char)va_arg(ap, int), par));
	return (ret > par[5] ? ret : par[5]);
}

int		ft_putptr_w(va_list ap, int par[9])
{
	int	len;
	int	arg;
	int	ret;
	int	i;

	i = 16;
	arg = (size_t)va_arg(ap, size_t);
	len = ft_nbrlen_base(arg, "0123456789abcdef");
	if (par[0] == -1)
		while (i++ < par[5])
			ft_putchar(' ');
	i = 0;
	while (i++ < 16 - len)
		ft_putchar('0');
	ret = (ft_putnbr_base_f(arg, "0123456789abcdef"));
	i = 16;
	if (par[0] != -1)
		while (i++ < par[5])
			ft_putchar(' ');
	return (ret > par[5] ? ret : par[5]);
}

char 	*get_base(int par[9])
{
	if (par[8] == 'd' || par[8] == 'i' || par[8] == 'u')
		return (ft_strdup("0123456789"));
	if (par[8] == 'p' || par[8] == 'x')
		return (ft_strdup("0123456789abcdef"));
	if (par[8] == 'o')
		return (ft_strdup("01234567"));
	if (par[8] == 'X')
		return (ft_strdup("0123456789ABCDEF"));
	return (NULL);
}

int		check_hash(int par[9])
{
	if (par[4] != -1)
	{
		if (par[8] == 'o')
		{
			ft_putchar('0');
			return (1);
		}
		if (par[8] == 'x')
		{
			ft_putstr("0x");
			return (2);
		}
		if (par[8] == 'X')
		{
			ft_putstr("0X");
			return (2);
		}
	}
	return (0);
}

int		ft_putnbr_uw(va_list ap, int par[9])
{
	int					len;
	unsigned long long	arg;
	char				*base;

	base = get_base(par);
	arg = get_nbr_by_bytes((unsigned long long)va_arg(ap, unsigned long long), par[7]);
	len = ft_nbrlen_base(arg, base) + (arg == 0 ? 0 : check_hash(par));
	while (par[5] > len && par[5] > par[6] && par[3] == -1 && par[0] == -1)
	{
		ft_putchar(' ');
		len++;
	}
	if (par[1] != -1)
		ft_putchar('+');
	while (len <= par[6] || (par[3] != -1 && par[5] > len))
	{
		ft_putchar('0');
		len++;
	}
	ft_putnbr_base_f(arg, base);
	while (par[0] != -1 && len < par[5])
	{
		ft_putchar(' ');
		len++;
	}
	return (len > par[5] ? len : par[5]);
}

int		ft_putnbr_w(va_list ap, int par[9])
{
	int			len;
	long long	arg;
	char		*base;

	base = get_base(par);
	arg = get_nbr_by_bytes((long long)va_arg(ap, long long), par[7]);
	len = ft_nbrlen_base(arg, base) + (par[3] == -1 || arg < 0? 0 : 1);
	while (par[5] > len && par[5] > par[6] && par[3] == -1 && par[0] == -1)
	{
		ft_putchar(' ');
		len++;
	}
	if (par[1] != -1 || arg < 0)
		ft_putchar((arg < 0 ? '-' : '+'));
	while (len <= par[6] || (par[3] != -1 && par[5] > len))
	{
		ft_putchar('0');
		len++;
	}
	ft_putnbr_base_f(arg, base);
	while (par[0] != -1 && len < par[5])
	{
		ft_putchar(' ');
		len++;
	}
	return (len > par[5] ? len : par[5]);
}

int		ft_putfloat_w(va_list ap, int par[9])
{
	int			len;
	long long	arg;
	char		*base;

	base = get_base(par);
	arg = get_nbr_by_bytes((long long)va_arg(ap, long long), par[7]);
	len = ft_nbrlen_base(arg, base) + (par[3] == -1 || arg < 0? 0 : 1);
	while (par[5] > len && par[5] > par[6] && par[3] == -1 && par[0] == -1)
	{
		ft_putchar(' ');
		len++;
	}
	if (par[1] != -1 || arg < 0)
		ft_putchar((arg < 0 ? '-' : '+'));
	while (len <= par[6] || (par[3] != -1 && par[5] > len))
	{
		ft_putchar('0');
		len++;
	}
	ft_putnbr_base_f(arg, base);
	while (par[0] != -1 && len < par[5])
	{
		ft_putchar(' ');
		len++;
	}
	return (len > par[5] ? len : par[5]);
}