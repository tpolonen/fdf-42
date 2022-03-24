/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:18:44 by tpolonen          #+#    #+#             */
/*   Updated: 2021/11/24 17:22:30 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signtest(long a, long b)
{
	if (a <= 0 && b <= 0)
		return (1);
	if (a == b)
		return (1);
	if (a >= 0 && b >= 0)
		return (1);
	return (0);
}

static long	ft_maxlong(int n)
{
	if (n < 0)
		return (-9223372036854775807LL - 1LL);
	else
		return (9223372036854775807LL);
}

int	ft_atoi(const char *nptr)
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
	{
		n = (10 * n) + ((long) sign * (*nptr++ - '0'));
		if (!ft_signtest(n, (long) sign))
			return ((int) ft_maxlong(sign));
	}
	return ((int) n);
}
