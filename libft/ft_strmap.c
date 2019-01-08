/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:01:34 by fratke            #+#    #+#             */
/*   Updated: 2018/12/02 00:40:32 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	len;
	unsigned int	i;
	char			*res;

	len = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[len] != '\0')
		len++;
	res = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (res != NULL)
	{
		while (i < len)
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
