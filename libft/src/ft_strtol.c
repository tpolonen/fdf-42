/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:19:38 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/07 10:15:23 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * To be implemented fully...
 * Current version sets the endptr to the char after the atoi'd number.
 * Different bases not implemented.
 * Needed in fdf map parsing.
 */

long	ft_strtol(const char *nptr, char **endptr)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		n = (10 * n) + ((long) sign * (*nptr++ - '0'));
	if (endptr != NULL)
		if (*endptr != NULL)
			*endptr = (char *)nptr;
	return (n);
}
