/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:43:12 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/20 13:55:10 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# ifdef LINUX
#  include <stdint.h>
# endif

# include "libft.h"
# include "get_next_line.h"

# define SIZE_X 1280
# define SIZE_Y 720

# define DEFAULT_SCALE 15.00
# define DEFAULT_MAGNITUDE 0.50

# define COS_30 0.8660254
# define SIN_30 0.5

typedef struct s_point2
{
	double	x;
	double	y;
}	t_point2;

typedef struct s_point3
{
	double	x;
	double	y;
	double	z;
}	t_point3;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		bytes_per_line;
	int		endian;
}	t_image;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	t_image		*bufs[2];
	int			**map;
	int			map_width;
	int			map_height;
	int			*cols;
	double		scale;
	double		magnitude;
	t_point2	margin;
}	t_param;

// Drawing related
// draw.c
void		dda_draw_line(t_image *i, t_point2 *p1, t_point2 *p2, uint32_t c);
uint32_t	rgb_to_uint(unsigned char r, unsigned char g, unsigned char b);
// map.c
void		render_map(t_param *params, t_image *buf);

// Reading and processing file
// fileread.c
void		read_file(char *filename, t_param *params);

#endif
