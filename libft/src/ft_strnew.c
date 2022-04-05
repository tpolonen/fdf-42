/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:17:09 by tpolonen          #+#    #+#             */
/*   Updated: 2021/12/13 14:17:59 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str)
		ft_bzero(str, sizeof(char) * (len + 1));
	return (str);
}
