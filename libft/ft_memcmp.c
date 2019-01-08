/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:19:18 by fratke            #+#    #+#             */
/*   Updated: 2018/11/22 20:49:37 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	if (n == 0)
		return (0);
	cptr1 = (unsigned char*)s1;
	cptr2 = (unsigned char*)s2;
	while (*cptr1 == *cptr2 && n-- > 1)
	{
		cptr1++;
		cptr2++;
	}
	return (*cptr1 - *cptr2);
}
