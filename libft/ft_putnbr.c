/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:12:08 by fratke            #+#    #+#             */
/*   Updated: 2018/11/28 22:54:00 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int	i;
	long int	k;
	long int	temp;
	char		c;

	k = 1;
	temp = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		temp = -temp;
	}
	i = temp;
	while (i > 9)
	{
		i = i / 10;
		k = k * 10;
	}
	while (k >= 1)
	{
		c = ((temp / k) % 10) + '0';
		write(1, &c, 1);
		k = k / 10;
	}
}
