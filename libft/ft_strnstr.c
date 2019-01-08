/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:27:32 by fratke            #+#    #+#             */
/*   Updated: 2018/12/01 21:47:31 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	if (*haystack == '\0')
		return (NULL);
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0] || needle[0] == '\0')
		{
			j = -1;
			while (needle[++j] != '\0' && i + j < len)
				if (haystack[i + j] != needle[j])
					break ;
			if (needle[j] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
