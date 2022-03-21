#include <mlx.h>
#include <stddef.h>
#include <stdio.h>
#define MAX_DRAW 64

typedef struct s_param
{
	void	*win;
	void	*mlx;
} t_param;

static void	(*draw_funcs[MAX_DRAW]) (void *) = { 0 };

int add_draw_func(void (*draw_func) (void *))
{
	int i = 0;
	while (i < MAX_DRAW && draw_funcs[i] != NULL) {
		i++;
	} if (i == MAX_DRAW) return (-1);
	draw_funcs[i] = draw_func;
	printf("draw funcs now contains:\n");
	for (int j = 0; j < MAX_DRAW && draw_funcs[j] != NULL; j++)
		printf("* %p\n", &draw_funcs[j]);
	return (1);
}

int update_frame(void *params)
{
	//printf("update running\n");
	int i = 0;
	while (i < MAX_DRAW && draw_funcs[i] != NULL)
		draw_funcs[i++](params);
	//printf("draw funcs processed\n");
	return (0);
}

void	draw_hello(void *params)
{
	static unsigned char r, g, b;
	r += 2;
	g += 4;
	b += 8;
	int color = b;
	color |= (g << (sizeof(char) * 8));
	color |= (r << ((sizeof(char) * 8) * 2));
	mlx_string_put(((t_param *)params)->mlx, ((t_param *)params)->win, 320, 180, color, "Hello world!");
	//printf("color is %d\n", color);
}

int main(void)
{
	void	*mlx;
	void	*win;
	t_param	params;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "Hello oWorld");
	params.mlx = mlx;
	params.win = win;
	
	printf("add_draw returned %d\n", add_draw_func(&draw_hello));
	mlx_loop_hook(win, &update_frame, &params);
	mlx_loop(mlx);
	return (0);
}
