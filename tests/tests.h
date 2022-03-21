#ifndef TESTS_H
# define TESTS_H

# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>

# define SIZE_X 640
# define SIZE_Y 360

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

//int	fill_color(t_image *img, int color);
#endif
