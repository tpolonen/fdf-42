/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:55:52 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:11:47 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l1;

	l1 = (t_list *) ft_memalloc(sizeof(t_list));
	if (!l1)
		return (NULL);
	if (content == NULL)
	{
		l1->content = NULL;
		l1->content_size = 0;
	}
	else
	{
		l1->content = malloc(content_size);
		if (!l1->content)
		{
			free(l1);
			return (NULL);
		}
		ft_memcpy(l1->content, content, content_size);
		l1->content_size = content_size;
	}
	l1->next = NULL;
	return (l1);
}
