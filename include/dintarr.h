/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dintarr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:21:53 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/06 14:05:12 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINTARR_H
# define DINTARR_H
# include "fdf.h"

typedef struct s_dintarr
{
	int		*arr;
	size_t	alloced;
	size_t	len;
}		t_dintarr;

int		dintarr_create(t_dintarr **darr, ssize_t size);
ssize_t dintarr_add(t_dintarr **darr, const int n);
ssize_t	dintarr_close(t_dintarr **src, int **dst);

#endif
