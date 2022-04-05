#include "tests.h"
#include <strings.h>
#include <math.h>

static t_point2 p1;
static t_point2 p2;

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
//	bzero(buf->addr, (buf->bytes_per_line * SIZE_Y));
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
