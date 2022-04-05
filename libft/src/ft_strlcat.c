/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:57 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:17:01 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;

	d = dst;
	while (*d && dstsize > 0)
	{
		d++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*d++ = *src++;
		dstsize--;
	}
	if (dstsize > 0)
		*d = '\0';
	return ((size_t)(d - dst) + ft_strlen(src));
}
