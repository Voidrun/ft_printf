/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:28:20 by fratke            #+#    #+#             */
/*   Updated: 2018/11/22 20:49:28 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	dstptr = dst;
	srcptr = (void*)src;
	while (n-- > 0)
	{
		*dstptr = *srcptr;
		dstptr++;
		srcptr++;
	}
	return (dst);
}
