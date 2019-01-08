/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:17:43 by fratke            #+#    #+#             */
/*   Updated: 2018/11/30 23:33:25 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

static void		undo_tab(char ***tab)
{
	int			i;

	i = 0;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		((*tab)[i] = NULL);
	}
	free(*tab);
	*tab = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	int			i;
	int			count;
	char		*tmp;

	tmp = (char*)s;
	if (s == NULL)
		return (NULL);
	count = wordcount(s, c);
	if ((res = (char**)malloc(sizeof(char*) * (count + 1))))
	{
		i = 0;
		while (i < count)
		{
			res[i] = makeword(&tmp, c);
			if (res[i] == NULL)
			{
				undo_tab(&res);
				return (NULL);
			}
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}
