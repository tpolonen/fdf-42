/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:21:00 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:25:41 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *elem)
{
	static int	i;

	if (!elem)
	{
		ft_putendl("Null list");
		return ;
	}
	ft_putchar('#');
	ft_putnbr(++i);
	ft_putstr(": [");
	ft_putmem(elem->content, elem->content_size);
	ft_putstr("] (size=");
	ft_putnbr((int) elem->content_size);
	ft_putendl(")");
	if (elem->next == NULL)
		i = 0;
}
