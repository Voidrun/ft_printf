/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:39:27 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 16:39:43 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_base_u(unsigned long long nbr, char *base)
{
	int len;
	int	base_len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (base)
	{
		base_len = ft_strlen(base);
		while (nbr != 0)
		{
			nbr = nbr / base_len;
			len++;
		}
	}
	return (len);
}

int	ft_nbrlen_base(long long int nbr, char *base)
{
	int len;
	int	base_len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	if (base)
	{
		base_len = ft_strlen(base);
		while (nbr != 0)
		{
			nbr = nbr / base_len;
			len++;
		}
	}
	return (len);
}
