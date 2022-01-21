#include "tests.h"

int	alternate_bands(t_image *img, uint32_t color, int bands)
{
	static int	offset;
	uint8_t 	*dst;
	int			x;
	int			y;
	int			height;
	int			draw;

	dst = (uint8_t *)img->addr;
	height = SIZE_Y / bands;
	y = offset;
	draw = bands % 2;
	while (bands > 0) {
		if (bands % 2 == draw) {
			int start_y = y;
			while (y < start_y + height && y < SIZE_Y) {
				x = 0;
				while (x < SIZE_X) {
					*(uint32_t *)(dst + (y * img->bytes_per_line) + x * (img->bits_per_pixel / 8)) = color;
					x++;
				}
				y++;
			}
			bands--;
		} else {
			int start_y = y;
			while (y < start_y + height && y < SIZE_Y) y++;
			bands--;
		}
	}
	offset++;
	if (offset > height) offset = 0;
	return (0);
}

int	render_frame(void *params)
{
	static int	cur_buf;
	t_param		*p;
	t_image		*buf;

	p = (t_param *)params;
	buf = (t_image *)p->bufs[cur_buf];
	fill_color(buf, 0x00BA42);
	alternate_bands(buf, 0x0042AACC, 6);
	mlx_put_image_to_window(p->mlx, p->win, buf->img, 0, 0);
	cur_buf = (cur_buf == 0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_param	params;
	t_image	img1;
	t_image img2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "tutorial1");
	img1.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.bytes_per_line, &img1.endian);
	img2.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.bytes_per_line, &img2.endian);
	printf("bits per pixel: %d, line length: %d, endian: %d\n", img1.bits_per_pixel, img1.bytes_per_line, img1.endian);
	params.mlx = mlx;
	params.win = win;
	params.bufs[0] = &img1;
	params.bufs[1] = &img2;
	render_frame(&params);
	mlx_loop_hook(mlx, &render_frame, &params);
	mlx_loop(mlx);
	return (0);
}
