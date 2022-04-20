/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:03:46 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/20 12:37:24 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	coord_to_point(t_point2 *p, int x, int y, int z)
{
	p->x = (x - z) * COS_30;
	p->y = -y + (x + z) * SIN_30;

	p->x *= 10;
	p->y *= 10;

	p->x += SIZE_X/2;
	p->y += SIZE_Y/2;

	printf("drawing point to x:%f y:%f\n", p->x, p->y);
}

void	render_map(t_param *params, t_image *buf, int margin_x, int margin_y)
{
	t_point2 cur;
	t_point2 next_x;
	t_point2 next_z;

	(void) margin_x;
	(void) margin_y;

	for (int z = 0; z < params->map_height - 1; z++) {
		for (int x = 0; x < params->cols[z] - 1; x++) {
			coord_to_point(&cur, x, params->map[z][x], z);
			coord_to_point(&next_x, x+1, params->map[z][x+1], z);
			coord_to_point(&next_z, x, params->map[z+1][x], z+1);
			dda_draw_line(buf, &cur, &next_x, 0x0042FF42);
			dda_draw_line(buf, &cur, &next_z, 0x00FF4242);
		}
	}
}
