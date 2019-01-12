/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:42:47 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 01:41:52 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	intlen(int n, int *k)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
		*k = *k * 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	tmp;
	int			i;
	int			j;
	int			k;
	char		*res;

	tmp = n;
	k = 1;
	i = intlen(tmp, &k);
	j = 0;
	if ((res = (char*)malloc(sizeof(char) * (i + 1))))
	{
		if (tmp < 0)
		{
			res[j++] = '-';
			tmp = -tmp;
		}
		while (k > 0)
		{
			res[j++] = ((tmp / k) % 10) + '0';
			k = k / 10;
		}
		res[j] = '\0';
	}
	return (res);
}

static int	intlen_l(long long n, long long *k, long long *tmp)
{
	int		i;

	*tmp = n;
	*k = 1;
	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
		*k = *k * 10;
	}
	return (i);
}

char		*ft_itoa_l(long long n)
{
	long long	tmp;
	int			i;
	int			j;
	long long	k;
	char		*res;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = intlen_l(n, &k, &tmp);
	j = 0;
	if ((res = (char*)malloc(sizeof(char) * (i + 1))))
	{
		if (tmp < 0)
		{
			res[j++] = '-';
			tmp = -tmp;
		}
		while (k > 0)
		{
			res[j++] = ((tmp / k) % 10) + '0';
			k = k / 10;
		}
		res[j] = '\0';
	}
	return (res);
}
