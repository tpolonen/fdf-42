#include "tests.h"

typedef struct s_param2
{
	void		*win;
	void		*mlx;
	t_image		*bufs[2];
	int			*coords;
	t_matrix2	*draw_matrix;
	int			magnitude;
	int			*map;
	int			nodecount;
} t_param2;

static uint32_t line_color = 0x0042FF42;
static uint32_t bg_color = 0x00000000;

int *read_input(int ac, char **av)
{
	(void) ac;
	(void) av;
	int nodecount = 10;
	int nodes = nodecount;
	int	*map = calloc(1, sizeof(int) * nodes);

	return (map);
}

void draw_map(t_image *cur_buf, t_param2 *params)
{
	double		gap = SIZE_X / (params->nodecount - 1);
	t_point2	last_point;
	t_point2	cur_point;
	
	for (int i = 0; i < params->nodecount; i++)
	{
//		printf("currently doing map index %d, containing %d\n", i, params->map[i]);
		cur_point.x = (int)round(gap) * i;
		cur_point.y = (SIZE_Y / 2) + (params->map[i] * params->magnitude);
		if (i > 0)
			dda_draw_line(cur_buf, &last_point, &cur_point, line_color);
		last_point.x = cur_point.x;
		last_point.y = cur_point.y;
	}
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
	draw_map(buf, params);
	// put curr. back buffer to window and flip buffers
	mlx_put_image_to_window(p->mlx, p->win, buf->img, 0, 0);
	cur_buf = (cur_buf == 0);
	return (0);
}

int main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	int			map[10] = { 0, 0, 0, 8, 4, 2, 5, 5, 5, 0 };
	int			nodecount = 10;
	t_matrix2	matrix;

	//assign matrix values individually because of course
	matrix.i_hat[0] = 1;
	matrix.i_hat[1] = 0;
	matrix.j_hat[1] = 0;
	matrix.j_hat[0] = 1;

	t_param2	params;
	t_image		img1;
	t_image 	img2;

	params.draw_matrix = &matrix;
	params.map = map;
	params.nodecount = nodecount;
	params.magnitude = 25;

	// later
	// map = read_input(ac, av);

	(void) ac;
	(void) av;

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
//	mlx_loop_hook(mlx, &render_frame, &params);
	mlx_key_hook(mlx, &read_key, &params);
	mlx_loop(mlx);
	return(0);
}
