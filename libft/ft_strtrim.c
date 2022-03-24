/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:31:17 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/24 14:39:53 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswtspc(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*str;

	start = 0;
	end = (unsigned int) ft_strlen(s) - 1;
	while (*(s + start) && ft_iswtspc(*(s + start)))
		start++;
	if (*(s + start) == '\0')
		return (ft_strnew(0));
	while ((s + end) > (s + start) && ft_iswtspc(*(s + end)))
		end--;
	str = ft_strsub(s, start, end - start + 1);
	return (str);
}
