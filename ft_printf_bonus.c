/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 22:41:36 by fratke            #+#    #+#             */
/*   Updated: 2019/01/15 22:41:59 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <fcntl.h>

int		ft_putfile_w(va_list *ap, int par[9])
{
	int		fd;
	int		ret;
	char	*str;

	ret = 0;
	(void)par;
	fd = (int)va_arg(*ap, int);
	while (get_next_line(fd, &str) > 0)
	{
		ret += ft_printf("%s\n", str);
		free(str);
	}
	return (ret);
}

int		ft_puttab_w(va_list *ap, int par[9])
{
	char	**tab;
	int		ret;

	ret = 0;
	(void)par;
	tab = (char**)va_arg(*ap, char**);
	if (!tab)
		return (ft_printf("(null)"));
	while (*tab)
	{
		ret += ft_printf("%s\n", *tab);
		tab++;
	}
	return (ret);
}

void	colors(char **fmt)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while ((*fmt)[i] != '}' && (*fmt)[i])
		i++;
	if (!(*fmt)[i])
		return ;
	if (ft_strnstr(*fmt, "red", i) && (flag = 1))
		ft_printf("\x1b[31m");
	if (ft_strnstr(*fmt, "green", i) && (flag = 1))
		ft_printf("\x1b[32m");
	if (ft_strnstr(*fmt, "yellow", i) && (flag = 1))
		ft_printf("\x1b[33m");
	if (ft_strnstr(*fmt, "blue", i) && (flag = 1))
		ft_printf("\x1b[34m");
	if (ft_strnstr(*fmt, "magenta", i) && (flag = 1))
		ft_printf("\x1b[35m");
	if (ft_strnstr(*fmt, "cyan", i) && (flag = 1))
		ft_printf("\x1b[36m");
	if (ft_strnstr(*fmt, "eoc", i) && (flag = 1))
		ft_printf("\x1b[0m");
	if (flag)
		*fmt += i + 1;
}
