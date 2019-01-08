/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:47:55 by fratke            #+#    #+#             */
/*   Updated: 2018/11/21 14:01:42 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	dstptr = (unsigned char*)dst;
	srcptr = (unsigned char*)src;
	while (n-- > 0)
	{
		*dstptr = *srcptr;
		if (*srcptr == (unsigned char)c)
			return (dstptr + 1);
		dstptr++;
		srcptr++;
	}
	return (NULL);
}
