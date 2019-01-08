/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:47:49 by fratke            #+#    #+#             */
/*   Updated: 2018/12/02 20:46:09 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		get_start(const char *s)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static int		get_end(const char *s)
{
	int		j;

	j = 0;
	while (s[j] != '\0')
		j++;
	if (j > 0)
		j--;
	while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char*)s);
	i = get_start(s);
	j = get_end(s);
	k = 0;
	if (i <= j && (res = (char*)malloc(sizeof(char) * (j - i + 2))))
	{
		while (i < j + 1)
			res[k++] = s[i++];
		res[k] = '\0';
	}
	else if (i > j && (res = (char*)malloc(sizeof(char))))
		*res = '\0';
	return (res);
}
