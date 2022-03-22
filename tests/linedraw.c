#include "tests.h"
#include <strings.h>
#include <math.h>

typedef struct s_point {
	int x;
	int y;
} t_point;

static t_point2 p1;
static t_point2 p2;

/*
void dda_draw_line(t_image *img, t_point *p1, t_point *p2, uint32_t color)
{
	uint8_t *dst;

//	printf("does this img have address? %p\n", img->addr);
	dst = (uint8_t *)img->addr;
	//calculate range for line between start and end point
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

	printf("do we have dst? %p\n", dst);
	printf("what's there? %d\n", *dst);
	printf("trying y: %zu\n", (size_t)(dst + (int)round(y) * img->bytes_per_line));
	printf("trying x: %zu\n", (size_t)((int)round(x) * (img->bits_per_pixel / 8)));

	*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	for (int i = 1; i <= step; ++i)
	{
		x += x_increment;
		y += y_increment;
		*(uint32_t *)(dst + ((int)y * img->bytes_per_line) + ((int)x * img->bytes_per_pixel)) = color;
	}
}
*/

uint32_t rgb_to_uint(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t color = (uint32_t)b;
	color |= (g << (sizeof(char) * 8));
	color |= (r << ((sizeof(char) * 8) * 2));
	return color;
}

int	render_frame(void *params)
{
	static int	cur_buf;
	static int	go_up;
	t_param		*p;
	t_image		*buf;
	static unsigned char r, g, b;

	r += 2;
	g += 4;
	b += 8;
	uint32_t color = rgb_to_uint(r, g ,b);
	p = (t_param *)params;
	buf = (t_image *)p->bufs[cur_buf];
	if (!go_up)
	{
		p1.y++;
		p2.y--;
		if (p1.y > SIZE_Y || p2.y < 0)
			go_up = 1;
	}
	else
	{
		p1.y--;
		p2.y++;
		if (p1.y < 0 || p2.y > SIZE_Y)
			go_up = 0;
	}
	bzero(buf->addr, (buf->bytes_per_line * SIZE_Y));
	dda_draw_line(buf, &p1, &p2, color);
	mlx_put_image_to_window(p->mlx, p->win, buf->img, 0, 0);
	cur_buf = (cur_buf == 0);
	return (0);
}

int main(void){
	void	*mlx;
	void	*win;
	t_param	params;
	t_image	img1;
	t_image img2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "linedraw");
	img1.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.bytes_per_line, &img1.endian);
	img1.bytes_per_pixel = img1.bits_per_pixel / 8;
	img2.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.bytes_per_line, &img2.endian);
	img2.bytes_per_pixel = img2.bits_per_pixel / 8;
	printf("img1 addr: %p\n", img1.addr);
	printf("img2 addr: %p\n", img2.addr);
	printf("bits per pixel: %d, bytes_per_pixel: %d, line length: %d, endian: %d\n", img1.bits_per_pixel, img1.bytes_per_pixel, img1.bytes_per_line, img1.endian);
	params.mlx = mlx;
	params.win = win;
	params.bufs[0] = &img1;
	params.bufs[1] = &img2;
	p1.x = 0;
	p1.y = 0;
	p2.x = SIZE_X;
	p2.y = SIZE_Y;
	render_frame(&params);
	mlx_loop_hook(mlx, &render_frame, &params);
	mlx_loop(mlx);
	return(0);
}
