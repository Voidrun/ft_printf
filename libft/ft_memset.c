/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:04:36 by fratke            #+#    #+#             */
/*   Updated: 2018/11/21 14:06:46 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bptr;

	bptr = (unsigned char*)b;
	while (len--)
	{
		*bptr = (unsigned char)c;
		bptr++;
	}
	return (b);
}
