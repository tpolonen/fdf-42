/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:43:12 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/02 16:07:22 by tpolonen         ###   ########.fr       */
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

# define PROJ_AMOUNT 3

# define COS_30 0.8660254
# define SIN_30 0.5
# define COS_42 0.7431448
# define SIN_42 0.6691306
# define SIN_7 0.1218693
# define COS_7 0.9925461

# define KEY_ESC   53    
# define KEY_TAB   48
# define KEY_LEFT  123  
# define KEY_RIGHT 124  
# define KEY_DOWN  125  
# define KEY_UP    126   
# define KEY_W     13   
# define KEY_A     0    
# define KEY_S     1    
# define KEY_D     2    
# define KEY_R     15

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

typedef void	(*t_proj)(t_point2 *p, t_point3 *c);

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
	t_proj		projs[PROJ_AMOUNT];
	int			cur_proj;
}	t_param;

/* Drawing related */
// draw.c
void		dda_draw_line(t_image *i, t_point2 *p1, t_point2 *p2, uint32_t c);
uint32_t	rgb_to_uint(unsigned char r, unsigned char g, unsigned char b);

// map.c
void		render_map(t_param *params, t_image *buf);

// coordinates.c
void		load_projections(t_proj projs[PROJ_AMOUNT]);

/* Reading and processing file */
// fileread.c
void		read_file(char *filename, t_param *params);

/* Events */
// events.c
int			event_keydown(int keycode, void *param);
void		handle_exit(char *msg, void *params);

// main.c
void		render_frame(t_param *p);

#endif
