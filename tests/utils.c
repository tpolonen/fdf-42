#include "tests.h"

int	fill_color(t_image *img, int color)
{
	uint8_t	*dst;
	int		i;

	dst = (uint8_t *)img->addr;
	i = 0;
	while (i < (SIZE_X * SIZE_Y)) {
		*(uint32_t *)dst = color;
		dst += img->bits_per_pixel / 8;
		i++;
	}
	return (0);
}
