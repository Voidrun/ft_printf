/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:37:08 by fratke            #+#    #+#             */
/*   Updated: 2018/12/21 02:26:06 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	while (s1 != NULL && s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
		j++;
	if ((res = (char*)malloc(sizeof(char) * (i + j + 10))))
	{
		i = 0;
		j = -1;
		while (s1 != NULL && s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[++j] != '\0' && n--)
			res[i + j] = s2[j];
		res[i + j] = '\0';
	}
	free(s1);
	return (res);
}

t_list		*ft_lstsearch(t_list *lst, size_t fd)
{
	int		i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			if (lst->content_size == fd)
				return (lst);
			lst = lst->next;
			i++;
		}
	}
	return (NULL);
}

void		ft_lstremove(t_list **lst, size_t fd)
{
	t_list	*curr;
	t_list	*prev;

	if (!lst)
		return ;
	prev = NULL;
	curr = *lst;
	while (curr)
	{
		if (curr->content_size == fd)
		{
			if (prev == NULL)
				*lst = curr->next;
			else
				prev->next = curr->next;
			free(curr->content);
			free(curr);
		}
		curr = curr->next;
	}
}

int			read_next_line(const int fd, char **line, t_list *tmp)
{
	char	*nl;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if (ft_strlen(tmp->content) > 0 && !(*line))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((nl = ft_strchr(buff, '\n')))
		{
			free(tmp->content);
			tmp->content = ft_strnjoin(0, nl + 1, ft_strlen(nl + 1));
			*line = ft_strnjoin(*line, buff, nl - buff);
			return (!tmp->content || !(*line) ? -1 : 1);
		}
		else
			*line = ft_strnjoin(*line, buff, ft_strlen(buff));
		if (!(*line))
			return (-1);
	}
	if (line && *line && ret == 0 && !(*((char*)(tmp->content)) = 0))
		return (1);
	return (ret >= 0 && line ? 0 : -1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char			*nl;
	t_list			*tmp;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!ft_lstsearch(lst, fd))
		ft_lstadd(&lst, ft_lstnew("", fd));
	tmp = ft_lstsearch(lst, fd);
	if ((nl = ft_strchr(tmp->content, '\n')))
	{
		*line = ft_strnjoin(NULL, tmp->content, (void*)nl - tmp->content);
		tmp->content = ft_strnjoin(NULL, nl + 1, ft_strlen(nl + 1));
		return (!tmp->content || !(*line) ? 0 : 1);
	}
	if (ft_strlen(tmp->content) > 0)
		*line = ft_strnjoin(*line, tmp->content, ft_strlen(tmp->content));
	if ((ret = read_next_line(fd, line, tmp)) > 0)
		return (1);
	ft_lstremove(&lst, fd);
	return (ret == 0 ? 0 : -1);
}
