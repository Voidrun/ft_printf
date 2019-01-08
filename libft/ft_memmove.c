/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:21:34 by fratke            #+#    #+#             */
/*   Updated: 2018/11/28 21:02:39 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;
	size_t			i;

	dstptr = (unsigned char*)dst;
	srcptr = (unsigned char*)src;
	i = 0;
	if (dstptr < srcptr)
	{
		while (i < len)
		{
			dstptr[i] = srcptr[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			dstptr[len] = srcptr[len];
		}
	}
	return (dst);
}
