/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:43:45 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:11:39 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freecontent(void *content, size_t size)
{
	(void) size;
	if (content != NULL)
		free(content);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*h1;

	head = f(lst);
	if (!head)
		return (NULL);
	lst = lst->next;
	h1 = head;
	while (lst != NULL)
	{
		h1->next = f(lst);
		if (h1->next == NULL)
		{
			ft_lstdel(&head, &ft_freecontent);
			return (NULL);
		}
		lst = lst->next;
		h1 = h1->next;
	}
	return (head);
}
