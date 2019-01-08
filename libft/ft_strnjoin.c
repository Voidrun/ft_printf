/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:04:34 by fratke            #+#    #+#             */
/*   Updated: 2018/12/01 22:32:44 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strnjoin(char *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	while (s1 != NULL && s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
		j++;
	if ((res = (char*)malloc(sizeof(char) * (i + j + 1))))
	{
		i = 0;
		j = -1;
		while (s1 != NULL && s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[++j] != '\0' && n--)
			res[i + j] = s2[j];
		res[i + j] = '\0';
	}
	return (res);
}
