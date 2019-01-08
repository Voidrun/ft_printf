/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:43:18 by fratke            #+#    #+#             */
/*   Updated: 2018/11/21 15:49:09 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char*)malloc(sizeof(char) * size + 1);
	i = 0;
	if (res != NULL)
	{
		while (i < size + 1)
		{
			res[i] = '\0';
			i++;
		}
	}
	return (res);
}
