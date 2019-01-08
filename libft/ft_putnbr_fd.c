/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:26:31 by fratke            #+#    #+#             */
/*   Updated: 2018/11/28 22:54:28 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	long int	i;
	long int	k;
	long int	temp;
	char		c;

	k = 1;
	temp = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
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
		write(fd, &c, 1);
		k = k / 10;
	}
}
