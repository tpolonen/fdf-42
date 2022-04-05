/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:00:33 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:17:48 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d1;

	d1 = dst;
	while (*src && len)
	{
		*d1++ = *src++;
		len--;
	}
	while (len)
	{
		*d1++ = '\0';
		len--;
	}
	return (dst);
}
