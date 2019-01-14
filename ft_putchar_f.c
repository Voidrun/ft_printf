/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 01:49:21 by fratke            #+#    #+#             */
/*   Updated: 2019/01/14 21:34:40 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_putchar_f(int c, int params[9])
{
	int	i;

	i = 0;
	if (params[0] == -1)
	{
		while (i < params[5] - 1)
		{
			ft_putchar(params[3] == -1 ? ' ' : '0');
			i++;
		}
	}
	ft_putchar(c);
	if (params[0] != -1)
	{
		while (i < params[5] - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (1);
}
