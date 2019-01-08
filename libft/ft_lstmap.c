/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:58:08 by fratke            #+#    #+#             */
/*   Updated: 2018/11/30 23:34:28 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	undo_map(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(lst);
	lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*iter;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(iter = f(lst)))
		return (NULL);
	res = iter;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(iter->next = f(lst)))
		{
			undo_map(&res);
			return (NULL);
		}
		iter = iter->next;
	}
	return (res);
}
