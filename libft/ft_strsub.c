/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:19:59 by fratke            #+#    #+#             */
/*   Updated: 2018/11/28 22:31:30 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (res != NULL)
	{
		while (i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
