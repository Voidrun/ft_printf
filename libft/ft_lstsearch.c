/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:48:34 by fratke            #+#    #+#             */
/*   Updated: 2018/12/01 21:50:59 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, void *value)
{
	if (lst)
	{
		while (lst)
		{
			if (ft_memcmp(value, lst->content, lst->content_size))
				return (lst);
			lst = lst->next;
		}
	}
	return (NULL);
}
