/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:03:46 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/03 23:08:43 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**free_map(int ***map, int **col_arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free((*map)[i++]);
	ft_memdel((void **)map);
	ft_memdel((void **)col_arr);
	return (NULL);
}	

static void	coord_to_point(t_point2 *p, t_point3 *c, t_param *params)
{
	params->projs[params->cur_proj](p, c);
	p->x *= params->scale;
	p->y *= params->scale;
	p->x += params->margin.x;
	p->y += params->margin.y;
}

static void	get_coord(t_param *params, t_point3 *coord, int x, int z)
{
	coord->x = x;
	coord->y = params->map[z][x] * params->magnitude;
	coord->z = z;
}

static void	draw_line(t_param *params, t_point2 *start, int x, int z)
{
	t_point2	end;
	t_point3	coord;
	t_image		*buf;

	buf = params->bufs[params->cur_buf];
	get_coord(params, &coord, x, z);
	coord_to_point(&end, &coord, params);
	dda_draw_line(buf, start, &end, params->color);
}

void	render_map(t_param *params)
{
	t_point2	cur;
	t_point3	coord;
	int			z;
	int			x;

	z = 0;
	while (z < params->map_height)
	{
		x = 0;
		while (x < params->cols[z])
		{
			get_coord(params, &coord, x, z);
			coord_to_point(&cur, &coord, params);
			if (z < params->map_height - 1)
				draw_line(params, &cur, x, z + 1);
			if (x < params->cols[z] - 1)
				draw_line(params, &cur, x + 1, z);
			x++;
		}
		z++;
	}
}
