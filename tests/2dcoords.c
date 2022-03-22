#include "tests.h"

static uint32_t line_color;
static uint32_t bg_color;

int *read_input(int ac, char **av)
{
	(void) ac;
	(void) av;

	int nodes = 10;
	int	*map = calloc(1, sizeof(int) * nodes);

	return (map);
}

int	render_frame(void *params)
{
	static int	cur_buf;
	t_param		*p;
	t_image		*buf;
	p = (t_param *)params;
	// open back buffer
	buf = (t_image *)p->bufs[cur_buf];
	// clear back buffer
	bzero(buf->addr, (buf->bytes_per_line * SIZE_Y));
	// do draw stuff
	0;
	// put curr. back buffer to window and flip buffers
	mlx_put_image_to_window(p->mlx, p->win, buf->img, 0, 0);
	cur_buf = (cur_buf == 0);
	return (0);
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		*map;
	t_param	params;
	t_image	img1;
	t_image img2;

	map = read_input(ac, av);
	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "2dcoord");
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
	render_frame(&params);
	mlx_loop_hook(mlx, &render_frame, &params);
	mlx_key_hook(mlx, &read_key, &params);
	mlx_loop(mlx);
	return(0);
}
