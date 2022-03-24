/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:28:24 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/14 18:07:20 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s1);
	while (n > 0 && *s2)
	{
		s1[i++] = *s2++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
