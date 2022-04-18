/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:13:12 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/18 13:43:46 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static uint32_t line_color = 0x0042FF42;
static uint32_t bg_color = 0x00000000;
/*
static void swap_images(t_image **img1, t_image **img2)
{
	t_image *temp;

	temp = *img1;
	*img1 = *img2;
	*img2 = temp;
}
*/
static void render_frame(t_param *params)
{
	static int	cur_buf;
	t_point2 	margin;

	margin.x = 50;
	margin.y = 50;

	printf("are we rendering frame\n");
	memset(params->bufs[cur_buf]->addr, 0x42,  (params->bufs[cur_buf]->bytes_per_line * SIZE_Y));
	render_map(params, params->bufs[cur_buf], margin);
	mlx_put_image_to_window(params->mlx, params->win, params->bufs[cur_buf], 0, 0);
	cur_buf = (cur_buf == 0);
	printf("rendered frame\n");
}

static void read_params(int ac, char **av, t_param *params)
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

	read_params(ac, av, &params);
	mlx = mlx_init();
	// probably should get rid of the repetition here
	img1.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.bytes_per_line, &img1.endian);
	img1.bytes_per_pixel = img1.bits_per_pixel / 8;
	img2.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.bytes_per_line, &img2.endian);
	img2.bytes_per_pixel = img2.bits_per_pixel / 8;
	printf("img1 addr: %p\n", img1.addr);
	printf("img2 addr: %p\n", img2.addr);
	printf("bits per pixel: %d, bytes_per_pixel: %d, line length: %d, endian: %d\n", img1.bits_per_pixel, img1.bytes_per_pixel, img1.bytes_per_line, img1.endian);
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "fdf");
	params.mlx = mlx;
	params.win = win;
	params.bufs[0] = &img1;
	params.bufs[1] = &img2;
	params.magnitude = 50;
	t_point2 zero;
	t_point2 end;
	zero.x = 0;
	zero.y = 0;
	end.x = SIZE_X;
	end.y = SIZE_Y;
	for (int i = 0; i < SIZE_X; i++) {
		mlx_pixel_put(params.mlx, params.win, i, SIZE_Y / 2, line_color);
	}
	memset(img1.addr, 0xFF, (img1.bytes_per_line * SIZE_Y));
	dda_draw_line(&img1, &zero, &end, line_color);
	mlx_put_image_to_window(params.mlx, params.win, &img1, 0, 0);
//	render_frame(&params);
	mlx_loop(mlx);
	return(0);
}
