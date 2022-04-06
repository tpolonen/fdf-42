	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   main.c                                             :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2022/04/05 11:48:29 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/06 18:13:58 by tpolonen         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

	// static uint32_t line_color = 0x0042FF42;
	// static uint32_t bg_color = 0x00000000;

static void render_frame(t_param *params)
{
	(void) params;
}

void read_input(int ac, char **av, t_param *params)
{
	if (ac == 2) 
	{
		read_file(av[1], params);
	} 
	else {
	printf("Invalid parameters: expected map filename, got %d arguments\n", ac - 1);
	exit(2);
	}
}

int main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_param		params;
	t_image		img1;
	t_image 	img2;

	// now
	// read_input needs to set map and nodecount
	// gotta love side-effects
	read_input(ac, av, &params);
	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "fdf");
	img1.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.bytes_per_line, &img1.endian);
	img1.bytes_per_pixel = img1.bits_per_pixel / 8;
	img2.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.bytes_per_line, &img2.endian);
	img2.bytes_per_pixel = img2.bits_per_pixel / 8;
	params.mlx = mlx;
	params.win = win;
	params.bufs[0] = &img1;
	params.bufs[1] = &img2;
	params.magnitude = 50;
	render_frame(&params);
	//mlx_loop(mlx);
	return(0);
}
