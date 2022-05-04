/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:46:03 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/04 12:20:12 by teppo            ###   ########.fr       */
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

void	dda_draw_line(t_image *img, t_point2 *p1, t_point2 *p2, uint32_t color)
{
	uint8_t	*dst;

	dst = (uint8_t *)img->addr;
	int dx = (int)p2->x - (int)p1->x;
	int dy = (int)p2->y - (int)p1->y;
	//calculate steps required for creating pixels
	int step = abs(abs(dx) > abs(dy) ? dx : dy);
	//calculate increment in x & y for each step
	double x_increment = (dx) / (double)step;
	double y_increment = (dy) / (double)step;
	//draw pixel for each step
	double x = p1->x;
	double y = p1->y;
	if (!(x >= SIZE_X || x < 0 || y >= SIZE_Y || y < 0)) *(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	for (int i = 1; i <= step; ++i)
	{
		x += x_increment;
		y += y_increment;
		if (x >= SIZE_X || x < 0 || y >= SIZE_Y || y < 0) continue;
		*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	}
}
