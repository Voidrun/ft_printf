/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:51:03 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:51:29 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	set_flags(char **fmt, int flags[10])
{
	int	i;

	i = -1;
	while (++i < 8)
		flags[i] = -1;
	i = 0;
	while (!ft_strchr("cspdiouxXUOfFS%", (*fmt)[i]))
		i++;
	if (ft_strnstr(*fmt, "-", i))
		flags[0] = 1;
	if (ft_strnstr(*fmt, "+", i))
		flags[1] = 1;
	if (ft_strnstr(*fmt, " ", i))
		flags[2] = 1;
	if (ft_strnstr(*fmt, "#", i))
		flags[4] = 1;
	i = 0;
	while (ft_strchr("-+ 0#", **fmt) && **fmt)
	{
		if (*fmt[i] == '0')
			flags[3] = 1;
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

void	get_len(char **fmt, int par[9])
{
	int		n;
	char	*tmp;

	n = 0;
	par[7] = 32;
	while ((!(ft_isalpha(fmt[0][n])) || ft_strchr("hljz", fmt[0][n]))
			&& fmt[0][n] && fmt[0][n] != '%')
		n++;
	if (ft_strnstr(*fmt, "hh", n))
		par[7] = 8;
	if ((tmp = ft_strnstr(*fmt, "h", n)) && *(tmp + 1) != 'h')
		par[7] = 16;
	if (ft_strnstr(*fmt, "l", n) || ft_strnstr(*fmt, "j", n) ||
			ft_strnstr(*fmt, "z", n))
		par[7] = 64;
	*fmt += n;
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
	get_len(fmt, par);
	par[8] = (int)**fmt;
}
