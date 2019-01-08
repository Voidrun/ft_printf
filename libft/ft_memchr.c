/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:06:43 by fratke            #+#    #+#             */
/*   Updated: 2018/11/23 19:13:03 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cptr;

	cptr = (unsigned char*)s;
	while (n-- != 0)
	{
		if (*cptr == (unsigned char)c)
			return ((void*)cptr);
		cptr++;
	}
	return (NULL);
}
