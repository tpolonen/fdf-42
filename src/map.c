/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:03:46 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/14 17:52:14 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}
