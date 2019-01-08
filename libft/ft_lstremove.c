/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:51:08 by fratke            #+#    #+#             */
/*   Updated: 2018/12/01 22:32:31 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstremove(t_list *lst, void *value)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (ft_memcmp(value, lst->content, lst->content_size))
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		return (tmp);
	}
	lst->next = ft_lstremove(lst->next, value);
	return (lst);
}
