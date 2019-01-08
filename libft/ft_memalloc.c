/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:16:55 by fratke            #+#    #+#             */
/*   Updated: 2018/11/21 15:21:59 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (unsigned char*)malloc(size);
	if (res != NULL)
	{
		while (i < size)
		{
			res[i] = 0;
			i++;
		}
	}
	return ((void*)res);
}
