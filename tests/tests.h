#ifndef TESTS_H
# define TESTS_H

# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define SIZE_X 1280
# define SIZE_Y 720

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		bytes_per_line;
	int		endian;
} t_image;

typedef struct s_param
{
	void	*win;
	void	*mlx;
	t_image	*bufs[2];
} t_param;

typedef struct s_list
{
	void	*content;
	int		size;
	struct s_list	*next;
} t_list;

typedef struct s_keybind
{
	int		keycode;
	void	(*func)(t_param *params);
} t_keybind;

typedef struct s_point2
{
	int	x;
	int	y;
} t_point2;

typedef struct s_point3
{
	int x;
	int y;
	int z;
} t_point3;

typedef struct s_matrix2
{
	int i_hat[2];
	int j_hat[2];
} t_matrix2;

typedef struct s_matrix3
{
	int i_hat[3];
	int j_hat[3];
	int k_hat[3];
} t_matrix3;

// List functions
t_list	*lstnew(void *content, size_t content_size);
void	lstadd(t_list **alst, t_list *new);

// Drawing related
void		dda_draw_line(t_image *img, t_point2 *p1, t_point2 *p2, uint32_t color);
uint32_t	rgb_to_uint(unsigned char r, unsigned char g, unsigned char b);

// Events and hooks
int 	set_key(int keycode, void (*func)(t_param *params));
int 	read_key(int keycode, void *params);

#endif
