/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:57:58 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:13:38 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *(const unsigned char *) s1 == *(const unsigned char *) s2)
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *) s1 - *(const unsigned char *) s2);
}
