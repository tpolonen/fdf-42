/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:29:37 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/24 17:47:32 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!len || dst == src)
		return (dst);
	if (src < dst && src + len > dst)
		while (len--)
			((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
