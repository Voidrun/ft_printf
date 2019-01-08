/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:51:22 by fratke            #+#    #+#             */
/*   Updated: 2018/12/02 00:46:41 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	if (!n)
		return (0);
	i = 0;
	while (i < n && s3[i] != 0 && s3[i] == s4[i])
	{
		i++;
	}
	if (i == n)
		i--;
	return (s3[i] - s4[i]);
}
