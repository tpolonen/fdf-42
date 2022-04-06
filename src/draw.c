/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:46:03 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/06 14:20:20 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t rgb_to_uint(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t color = (uint32_t)b;
	color |= (g << (sizeof(char) * 8));
	color |= (r << ((sizeof(char) * 8) * 2));
	return color;
}

void dda_draw_line(t_image *img, t_point2 *p1, t_point2 *p2, uint32_t color)
{
	uint8_t *dst;
	int		dx;
	int		dy;
	int		step;
	double	x_increment;
	double	y_increment;
	double	x;
	double	y;

	dst = (uint8_t *)img->addr;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	step = abs(abs(dx) > abs(dy) ? dx : dy);
	x_increment = dx / (double)step;
	y_increment = dy / (double)step;
	x = p1->x;
	y = p1->y;
	*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	for (int i = 1; i <= step; ++i)
	{
		x += x_increment;
		y += y_increment;
		*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	}
}
