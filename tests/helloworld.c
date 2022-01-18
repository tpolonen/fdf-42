#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "Hwello uWu");
	mlx_loop(mlx);
}
