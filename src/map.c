/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:03:46 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/18 13:11:28 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2	*coord_to_point(t_point2 *p, int x, int y, int z)
{
	p->x = (x - y) * COS_30;
	p->y = -z + (x + y) * SIN_30;

	p->x *= 10;
	p->y *= 10;

	p->x += SIZE_X/2;
	p->y += SIZE_Y/2;

	printf("drawing point to x:%d y:%d\n", p->x, p->y);
	return (p);
}

void	render_map(t_param *params, t_image *buf, t_point2 start_pos)
{
	(void)start_pos;

	t_point2 *cur = (t_point2*)ft_memalloc(sizeof(t_point2));
	t_point2 *next_x = (t_point2*)ft_memalloc(sizeof(t_point2));
	t_point2 *next_z = (t_point2*)ft_memalloc(sizeof(t_point2));

	for (int z = 0; z < params->map_height - 1; z++) {
		for (int x = 0; x < params->cols[z] - 1; x++) {
			cur = coord_to_point(cur, x, params->map[z][x], z);
			next_x = coord_to_point(next_x, x+1, params->map[z][x+1], z);
			next_z = coord_to_point(next_z, x, params->map[z+1][x], z+1);
			dda_draw_line(buf, cur, next_x, 0x00FF4200);
			dda_draw_line(buf, cur, next_z, 0x004200FF);
		}
	}

	ft_memdel((void **)&cur);
	ft_memdel((void **)&next_x);
	ft_memdel((void **)&next_z);
}
