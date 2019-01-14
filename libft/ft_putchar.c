/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:04:01 by fratke            #+#    #+#             */
/*   Updated: 2019/01/14 21:40:30 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	int					i;
	int					j;
	unsigned char		str[4];

	if (c < 128 && write(1, &c, 1))
		return ;
	str[0] = 0;
	str[1] = 0;
	str[2] = 0;
	str[3] = 0;
	i = 31;
	j = 0;
	while (!(c & 1 << i))
		i--;
	while (c & 1 << i--)
		j++;
	i = j;
	while (j--)
	{
		str[j] |= c;
		c >>= 8;
	}
	write(1, str, i);
}
