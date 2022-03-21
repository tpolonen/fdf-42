#include <mlx.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE_X 640
#define SIZE_Y 360

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
} t_image;

typedef struct s_param
{
	void	*win;
	void	*mlx;
	t_image	*bufs[2];
} t_param;

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

int	draw_band(t_image *img, uint32_t color, int y, int height)
{
	int		x;
	uint8_t *dst;

	dst = (uint8_t *)img->addr;
	while (y < height && y < SIZE_Y) {
		x = 0;
		while (x < SIZE_X) {
			*(uint32_t *)(dst + (y * img->bytes_per_line) + x * (img->bits_per_pixel / 8)) = color;
			x++;
		}
		y++;
	}
	return (0);
}

int	alternate_bands(t_image *img, uint32_t color, int bands)
{
	static int	offset;
	static int	pause;
	static int	draw;
	int			y;
	int			height;

	height = SIZE_Y / bands;
	/*
	if (draw) {
		draw_band(img, color, 0, height);
		y = height;
	}
		else*/ y = offset;
	while (bands > 0) {
		if (bands % 2 == draw) {
			draw_band(img, color, y, y + height);
			bands--;
		} else {
			int start_y = y;
			while (y < start_y + height && y < SIZE_Y) y++;
			bands--;
		}
	}
	if (pause < 10) pause++;
	else
	{
		pause = 0;
		offset++;
		if (offset > height)
		{
//			draw = (draw == 0);
			offset = 0;
		}

	}
	return (0);
}

int	render_frame(void *params)
{
	static int	cur_buf;
	t_param		*p;
	t_image		*buf;

	p = (t_param *)params;
	buf = (t_image *)p->bufs[cur_buf];
	fill_color(buf, 0x004242FF);
	alternate_bands(buf, 0x00FF4242, 6);
	mlx_put_image_to_window(p->mlx, p->win, buf->img, 0, 0);
	cur_buf = (cur_buf == 0);
	return (0);
}

int check_key(int keycode, void *params)
{
	(void) params;
	printf("%d was pressed\n", keycode);
	if (keycode == 65307)
		exit(0);
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
	mlx_key_hook(win, &check_key, &params);
	mlx_loop(mlx);

	return (0);
}
