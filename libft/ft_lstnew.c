/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:51:26 by fratke            #+#    #+#             */
/*   Updated: 2018/12/02 20:24:31 by fratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res)
	{
		if ((res->content = (void*)malloc(content_size)))
		{
			res->next = NULL;
			if (content)
			{
				ft_memcpy(res->content, content, content_size);
				res->content_size = content_size;
			}
			else
			{
				res->content = NULL;
				res->content_size = 0;
			}
		}
		else
			res = NULL;
		res->next = NULL;
	}
	return (res);
}
