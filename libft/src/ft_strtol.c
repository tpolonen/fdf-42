/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:19:38 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/06 16:00:55 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
 * To be implemented fully...
 * endptr, if not NULL, is set to first invalid character after atoi'd long..
 * Different bases not yet implemented.
 * Needed in fdf map parsing.
 */
static long	getlong(char sign, char *nptr, char *start, char **endptr)
{
	int		isnum;
	long	n;

	isnum = 0;
	n = 0;
	while (ft_isdigit(*nptr))
	{
		isnum = 1;
		n = (10 * n) + ((long) sign * (*nptr++ - '0'));
	}
	if (endptr != NULL)
	{
		if (*endptr != NULL && isnum)
			*endptr = (char *)nptr;
		else if (*endptr != NULL)
			*endptr = start;
	}
	return (n);
}

long	ft_strtol(const char *nptr, char **endptr)
{
	long	n;
	char	sign;
	char	*start;

	sign = 1;
	start = (char *) nptr;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	n = getlong(sign, (char *) nptr, start, endptr);
	return (n);
}
