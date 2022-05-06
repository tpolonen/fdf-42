/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:03:46 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/06 19:32:12 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**free_map(int ***map, int **col_arr, int rows)
{
	int	i;

	if (!(map))
		return (NULL);
	if (!(*map))
		return (NULL);
	i = 0;
	while (i < rows)
		free((*map)[i++]);
	ft_memdel((void **)map);
	ft_memdel((void **)col_arr);
	return (NULL);
}	

static void	get_point(t_param *params, t_point2 *buf_pos, int x, int z)
{
	t_point3	coord;

	coord.x = x;
	coord.y = params->map[z][x] * params->magnitude;
	coord.z = z;
	params->projs[params->cur_proj](buf_pos, &coord);
	buf_pos->x *= params->scale;
	buf_pos->y *= params->scale;
	buf_pos->x += params->margin.x;
	buf_pos->y += params->margin.y;
}

static double	dist_to_middle(t_point2 *point)
{
	return (sqrt(pow(fabs(point->x - (SIZE_X / 2)), 2.0) + \
			pow(fabs(point->y - (SIZE_Y / 2)), 2.0)));
}

static void	draw_line(t_param *p, t_point2 *p1, int x, int z)
{
	t_point2	p2;

	get_point(p, &p2, x, z);
	if ((p1->x > SIZE_X && p2.x > SIZE_X) || (p1->x < 0 && p2.x < 0) \
			|| (p1->y > SIZE_Y && p2.y > SIZE_Y) || (p1->y < 0 && p2.y < 0))
		return ;
	if (dist_to_middle(p1) < dist_to_middle(&p2))
		dda_draw_line(p, p1, &p2);
	else
		dda_draw_line(p, &p2, p1);
}

void	render_map(t_param *params)
{
	t_point2	cur;
	int			x;
	int			z;

	z = 0;
	while (z < params->map_height)
	{
		x = 0;
		while (x < params->cols[z])
		{
			get_point(params, &cur, x, z);
			if (z < params->map_height - 1)
				draw_line(params, &cur, x, z + 1);
			if (x < params->cols[z] - 1)
				draw_line(params, &cur, x + 1, z);
			x++;
		}
		z++;
	}
}
