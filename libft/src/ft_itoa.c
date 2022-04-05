/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:49:02 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:11:05 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_intlen(n, 10);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		return (ft_strcpy(str, "0"));
	while (n != 0)
	{
		str[len--] = '0' + (char)(ft_abs(n % 10));
		n /= 10;
	}
	if (len == 0)
		str[len] = '-';
	return (str);
}
