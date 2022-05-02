/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:02:01 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/02 15:57:10 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_point2 *p, t_point3 *c)
{
	p->x = (c->x - c->z) * COS_30;
	p->y = -c->y + (c->x + c->z) * SIN_30;
}

static void	dimetric(t_point2 *p, t_point3 *c)
{
	p->x = c->x * COS_7 + c->z * COS_42 / 2.0;
	p->y = -c->y + c->z * SIN_42 / 2.0 - c->x * SIN_7;
}

static void	scroll(t_point2 *p, t_point3 *c)
{
	p->x = c->x + 0.6 * c->z * COS_30;
	p->y = -c->y + 0.6 * c->z * SIN_30;
}

void	load_projections(t_proj projs[PROJ_AMOUNT])
{
	projs[0] = &isometric;
	projs[1] = &dimetric;
	projs[2] = &scroll;
}
