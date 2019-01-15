/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:33:36 by fratke            #+#    #+#             */
/*   Updated: 2019/01/15 22:52:02 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putstr_fw(int *str, int params[9])
{
	int	i;
	int	len;

	if (!str)
		return (ft_printf("%*.*s", params[5], params[6], "(null)"));
	i = -1;
	len = ft_strlen_w(str);
	if (params[6] > 0 && params[6] < len)
		len = params[6];
	if (params[0] != -1)
	{
		while (str[++i] && (i < params[6] || !params[6]))
			ft_putchar(str[i]);
		while (i++ < params[5])
			ft_putchar(' ');
		i--;
	}
	else
	{
		while (params[5] > len++)
			ft_putchar(' ');
		while (str[++i] && (i < params[6] || !params[6]))
			ft_putchar(str[i]);
	}
	return (i);
}

int	ft_putstr_f(char *str, int params[9])
{
	int	i;
	int	len;

	if (!str)
		return (ft_printf("(null)"));
	i = -1;
	len = ft_strlen(str);
	if (params[6] > 0 && params[6] < len)
		len = params[6];
	if (params[0] != -1)
	{
		while (str[++i] && (i < params[6] || !params[6]))
			ft_putchar(str[i]);
		while (i++ < params[5])
			ft_putchar(' ');
		i--;
	}
	else
	{
		while (params[5] > len++)
			ft_putchar((params[3] == 1) ? ('0') : (' '));
		while (str[++i] && (i < params[6] || !params[6]))
			ft_putchar(str[i]);
	}
	return (i);
}
