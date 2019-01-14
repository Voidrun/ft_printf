/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:47:34 by fratke            #+#    #+#             */
/*   Updated: 2019/01/14 21:44:53 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
		*fmt += i;
}
