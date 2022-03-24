/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:52:13 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:17:18 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	s2 = (char *) malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	while (len-- > 0)
		s2[len] = f(s[len]);
	return (s2);
}
