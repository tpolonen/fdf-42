/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:43:12 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/05 12:09:49 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

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
	int		*coords;
	int		magnitude;
	int		*map;
	int		nodecount;
} t_param;

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

// Drawing related
void		dda_draw_line(t_image *img, t_point2 *p1, t_point2 *p2, uint32_t color);
uint32_t	rgb_to_uint(unsigned char r, unsigned char g, unsigned char b);

// Reading and processing file
void 		read_file(char* filename, t_param2 *params);
