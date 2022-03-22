#include "tests.h"

void dda_draw_line(t_image *img, t_point2 *p1, t_point2 *p2, uint32_t color)
{
	uint8_t *dst;

	dst = (uint8_t *)img->addr;
	int dx = p2->x - p1->x;
	int dy = p2->y - p1->y;
	//calculate steps required for creating pixels
	int step = abs(abs(dx) > abs(dy) ? dx : dy);
	//calculate increment in x & y for each step
	double x_increment = (dx) / (double)step;
	double y_increment = (dy) / (double)step;
	//draw pixel for each step
	double x = p1->x;
	double y = p1->y;
	*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	for (int i = 1; i <= step; ++i)
	{
		x += x_increment;
		y += y_increment;
		*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	}
}
