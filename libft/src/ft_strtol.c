/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:19:38 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/05 21:25:25 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
 * To be implemented fully...
 * Current version sets the endptr to the char after the atoi'd number.
 * Different bases not implemented.
 * Needed in fdf map parsing.
 * One difference to libc's strol: doesn't skip over newlines.
 */

static int	ft_iswspace(int c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long	ft_strtol(const char *nptr, char **endptr)
{
	long	n;
	int		isnum;
	int		sign;
	char	*start;

	n = 0;
	isnum = 0;
	sign = 1;
	start = (char *) nptr;
	while (ft_iswspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		isnum = 1;
		n = (10 * n) + ((long) sign * (*nptr++ - '0'));
	}
	if (endptr != NULL)
	{
		if (*endptr != NULL && isnum)
			*endptr = (char *)nptr;
		else
			*endptr = start;
	}
	printf("returning %ld\n", n);
	return (n);
}
