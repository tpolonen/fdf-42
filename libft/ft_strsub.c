/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:56:10 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:18:27 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	sub[len] = '\0';
	while (len > 0)
	{
		len--;
		sub[len] = s[start + len];
	}
	return (sub);
}
