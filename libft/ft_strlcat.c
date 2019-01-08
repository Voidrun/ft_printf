/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:17:32 by fratke            #+#    #+#             */
/*   Updated: 2018/11/22 20:48:30 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		n;
	const char	*s;

	s = src;
	i = 0;
	j = 0;
	while (dst[i] != '\0' && size - i != 0)
		i++;
	while (src[j] != '\0')
		j++;
	n = size - i;
	if (n == 0)
		return (i + j);
	j = i;
	while (*src != '\0')
	{
		if (n != 1 && n--)
			dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return (j + (src - s));
}
