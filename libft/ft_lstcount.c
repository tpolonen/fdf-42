/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:11:06 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/05 17:15:26 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list *alst)
{
	size_t	count;

	count = 0;
	while (alst != NULL)
	{
		alst = alst->next;
		count++;
	}
	return (count);
}
