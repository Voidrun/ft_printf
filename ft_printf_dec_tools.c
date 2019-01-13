/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:38:16 by fratke            #+#    #+#             */
/*   Updated: 2019/01/13 15:44:11 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char		*get_width(int len, int par[9])
{
	char	*res;
	int		i;
	int		diff;

	diff = par[5] - len;
	if (diff > 0)
	{
		res = (char*)malloc(sizeof(char) * (diff + 1));
		i = 0;
		while (i < diff)
		{
			res[i] = (par[0] == -1 && par[3] == 1 ? '0' : ' ');
			if (par[6] < par[5] && par[3] == 1 && par[0] == -1
					&& par[6] != 0)
				res[i] = ' ';
			i++;
		}
		res[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (res);
}

char		*get_prec(int len, int par[9])
{
	char	*res;
	int		i;
	int		diff;

	diff = par[6] - len;
	if (diff > 0)
	{
		res = (char*)malloc(sizeof(char) * (diff + 1));
		i = 0;
		while (i < diff)
		{
			res[i] = '0';
			i++;
		}
		res[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (res);
}

char		*get_sign(char **nstr, int par[9])
{
	par[4] = 0;
	if (par[1] == 1 && *nstr[0] != '-')
		return (ft_strdup("+"));
	if (par[2] == 1 && *nstr[0] != '-')
		return (ft_strdup(" "));
	if (*nstr[0] == '-')
	{
		par[4] = 1;
		(*nstr)++;
		return (ft_strdup("-"));
	}
	return (ft_strdup(""));
}
