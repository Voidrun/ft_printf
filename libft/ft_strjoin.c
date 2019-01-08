/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:33:16 by fratke            #+#    #+#             */
/*   Updated: 2018/11/28 22:31:50 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if ((res = (char*)malloc(sizeof(char) * (i + j + 1))))
	{
		i = -1;
		j = -1;
		while (s1[++i] != '\0')
			res[i] = s1[i];
		while (s2[++j] != '\0')
			res[i + j] = s2[j];
		res[i + j] = '\0';
	}
	return (res);
}
