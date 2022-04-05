/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:45:18 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/23 19:15:27 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cpoint;

	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	cpoint = NULL;
	while (*s)
	{
		if (*s == (unsigned char) c)
			cpoint = s;
		s++;
	}
	return ((char *) cpoint);
}
