/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:27:32 by fratke            #+#    #+#             */
/*   Updated: 2018/11/30 21:32:47 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int match;

	i = 0;
	while (haystack[i] != '\0' || needle[0] == '\0')
	{
		match = 1;
		if (haystack[i] == needle[0] || needle[0] == '\0')
		{
			j = 0;
			while (needle[j] != '\0')
			{
				if (needle[j] != haystack[i + j])
					match = 0;
				j++;
			}
			if (match)
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
