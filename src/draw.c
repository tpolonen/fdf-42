/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:46:03 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/20 13:49:37 by tpolonen         ###   ########.fr       */
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

void dda_draw_line(t_image *img, t_point2 *p1, t_point2 *p2, uint32_t color)
{
	uint8_t *dst;

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
	if (x >= SIZE_X || x < 0 || y > SIZE_Y || y < 0) return;
	*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	for (int i = 1; i <= step; ++i)
	{
	//	printf(".");
		x += x_increment;
		y += y_increment;
		if (x >= SIZE_X || x < 0 || y > SIZE_Y || y < 0) break;
		*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	}
//	printf("\n");
}
