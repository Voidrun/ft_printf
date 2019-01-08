/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:17:43 by fratke            #+#    #+#             */
/*   Updated: 2018/12/01 22:29:27 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		wordcount(char const *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != '\0' && s[i] != c)
			res++;
		i++;
	}
	return (res);
}

static char		*makeword(char **str, char c)
{
	int		i;
	char	*res;
	char	*s;

	i = 0;
	s = *str;
	while (*s == c)
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	res = (char*)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	*str = s + i;
	res[i] = '\0';
	return (res);
}

t_list			*ft_strsplit_list(char *s, char c)
{
	t_list		*res;
	t_list		*node;
	int			i;
	int			j;
	int			count;

	if (s == NULL)
		return (NULL);
	count = wordcount(s, c);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			j++;
		if ((node = ft_lstnew(makeword(&s, c), j + 1)))
			ft_lstadd(&res, node);
		i++;
	}
	return (res);
}
