/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_by_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:38:06 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 16:40:26 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int			get_nbr_by_bytes(long long int nbr, int bytes)
{
	long long int	res;
	int				i;
	int				neg;

	i = 0;
	res = 0;
	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
	}
	while (i < bytes)
	{
		if (nbr & (1LL << i))
		{
			res |= (1LL << i);
		}
		i++;
	}
	return (neg ? -res : res);
}

unsigned long long		get_nbr_by_bytes_u(unsigned long long nbr,
		int bytes)
{
	unsigned long long		res;
	int						i;

	i = 0;
	res = 0;
	while (i < bytes)
	{
		if (nbr & (1ULL << i))
		{
			res |= (1ULL << i);
		}
		i++;
	}
	return (res);
}
