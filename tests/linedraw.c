#include "tests.h"
#include <math.h>

typedef struct s_point {
	int x;
	int y;
} t_point;

void dda_draw_line(t_point *p1, t_point *p2, t_param *params){
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
	mlx_pixel_put(params->mlx, params->win, (int)x, (int)y, 0x004242FF);
	for (int i = 1; i <= step; ++i)
	{
		x += x_increment;
		y += y_increment;
		mlx_pixel_put(params->mlx, params->win, (int)round(x), (int)round(y), 0x004242FF);
	}
}

int	render_frame(void *params)
{
//	static int	cur_buf;
	t_param		*p;
//	t_image		*buf;
	t_point		p1;
	t_point		p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = SIZE_X;
	p2.y = SIZE_Y;
	p = (t_param *)params;
//	buf = (t_image *)p->bufs[cur_buf];
	/*mlx_put_image_to_window(p->mlx, p->win, buf->img, 0, 0);
	cur_buf = (cur_buf == 0);
	*/
	dda_draw_line(&p1, &p2, p);
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
	img2.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.bytes_per_line, &img2.endian);
	printf("bits per pixel: %d, line length: %d, endian: %d\n", img1.bits_per_pixel, img1.bytes_per_line, img1.endian);
	params.mlx = mlx;
	params.win = win;
	params.bufs[0] = &img1;
	params.bufs[1] = &img2;
	render_frame(&params);
	mlx_loop(mlx);
	return(0);
}
