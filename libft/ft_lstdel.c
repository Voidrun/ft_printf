/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:10:15 by fratke            #+#    #+#             */
/*   Updated: 2018/11/30 23:30:38 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lptr;
	t_list	*n;

	if (alst != NULL && del != NULL)
	{
		lptr = *alst;
		while (lptr)
		{
			n = lptr->next;
			del(lptr->content, lptr->content_size);
			free(lptr);
			lptr = n;
		}
		*alst = NULL;
	}
}
