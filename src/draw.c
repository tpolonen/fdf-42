/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:46:03 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/06 19:15:47 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	rgb_to_uint(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t	color;

	color = (uint32_t)b;
	color |= (g << (sizeof(char) * 8));
	color |= (r << ((sizeof(char) * 8) * 2));
	return (color);
}

void	put_instructions(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 10, 10, 0x00FFFFFF,
		"W/A/S/D: Move camera");
	mlx_string_put(p->mlx, p->win, 10, 30, 0x00FFFFFF,
		"Up/Down: Scale height");
	mlx_string_put(p->mlx, p->win, 10, 50, 0x00FFFFFF,
		"Left/Right: Zoom");
	mlx_string_put(p->mlx, p->win, 10, 70, 0x00FFFFFF,
		"Tab: Change projection");
	mlx_string_put(p->mlx, p->win, 10, 90, 0x00FFFFFF,
		"R: Toggle this text");
	mlx_string_put(p->mlx, p->win, 10, 110, 0x00FFFFFF,
		"Esc: Exit");
}

static int	check_bounds(double dx, double dy, double xtrend, double ytrend)
{
	if (dx < 0)
	{
		if (xtrend < 0)
			return (-1);
		return (0);
	}
	else if (dx >= SIZE_X)
	{
		if (xtrend > 0)
			return (-1);
		return (0);
	}
	if (dy < 0)
	{
		if (ytrend < 0)
			return (-1);
		return (0);
	}
	else if (dy >= SIZE_Y)
	{
		if (ytrend > 0)
			return (-1);
		return (0);
	}
	return (1);
}

static void	dda_put_pixels(t_param *p, t_point2 *draw, t_point2 *inc, int step)
{
	int		res;

	while (step > 0)
	{
		res = check_bounds(draw->x, draw->y, inc->x, inc->y);
		if (res <= 0)
		{
			if (res < 0)
				break ;
			draw->x += inc->x;
			draw->y += inc->y;
			continue ;
		}
		*(uint32_t *)(p->bufs[p->cur_buf]->addr + \
				((int)draw->y * \
				p->bufs[p->cur_buf]->bytes_per_line) + \
				((int)draw->x * \
				p->bufs[p->cur_buf]->bytes_per_pixel)) \
				= p->color;
		draw->x += inc->x;
		draw->y += inc->y;
		step--;
	}
}

void	dda_draw_line(t_param *params, t_point2 *p1, t_point2 *p2)
{
	int			step;
	t_point2	dist;
	t_point2	increments;
	t_point2	draw;

	dist.x = p2->x - p1->x;
	dist.y = p2->y - p1->y;
	if (abs(dist.x) > abs(dist.y))
		step = abs(dist.x);
	else
		step = abs(dist.y);
	increments.x = (dist.x) / (double)step;
	increments.y = (dist.y) / (double)step;
	draw.x = p1->x;
	draw.y = p1->y;
	dda_put_pixels(params, &draw, &increments, step);
}
