/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:03:46 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/18 12:25:18 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2	*coord_to_point(t_point2 *p, int x, int y, int z)
{
	p->x = (x - y) * COS_30;
	p->y = -z + (x + y) * SIN_30;
	return (p);
}

void	render_map(t_params *params, t_point2 start_pos)
{
	//start drawing from start pos
	//--> start pos becomes the 0,0,0 to the map coordinates
	//then basically we use the scale to determine where the following nodes should be drawn:
	//10,10,10 would tell that one unit of each direction is 10 pixels away.
	//THEN we need to take the projection in the account somehow.

	//terminology: POINT is a coordinate on window - literal byte in the memory where
	//we can put a single pixel. NODE is a coordinate in 3d-space, which are connected
	//to each other with lines we draw on the screen.

	//maybe it's time to bring back matrices, at least I understood those kinda.

	//but let's say that with some amount of prayer, math, despair and spit we
	//managed to find out where the next point from origo should be drawn.
	//We move from left to right first, then when we do the next row, we connect
	//each of the nodes to the one before it in x-axis and one before it in z-axis.
	//Thus eventually whole map will be covered.

	//There might be some math that helps us occlude the hidden surfaces and lines.
	
	//We only start drawing from the second node.

	t_point2 *cur = (t_point2*)ft_memalloc(sizeof(t_point2));
	t_point2 *next_x = (t_point2*)ft_memalloc(sizeof(t_point2));
	t_point2 *next_z = (t_point2*)ft_memalloc(sizeof(t_point2));

	for (int z = 0; z < map_height - 1; z++) {
		for (int x = 0; x < params->cols[y] - 1; x++) {
			cur = coord_to_point(cur, x, params->map[z][x], z);
			next_x = coord_to_point(next_x, x+1, params->map[z][x+1], z);
			next_z = coord_to_point(next_z, x, params->map[z+1][x], z+1);
			dda_draw_line(params->bufs[0], cur, next_x, 0x00FFFFFF);
			dda_draw_line(params->bufs[0], cur, next_z, 0x00FFFFFF);
		}
	}

	ft_memdel(&cur);
	ft_memdel(&next_x);
	ft_memdel(&next_z);
}
