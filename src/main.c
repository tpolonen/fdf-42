/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:03:05 by tpolonen          #+#    #+#             */
/*   Updated: 2022/04/20 14:08:07 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_params(int ac, char **av, t_param *params)
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

static t_image	*init_buff(void *mlx, t_image *buff)
{
	buff->img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	buff->addr = mlx_get_data_addr(buff->img, &buff->bits_per_pixel,
			&buff->bytes_per_line, &buff->endian);
	buff->bytes_per_pixel = buff->bits_per_pixel / 8;
	ft_bzero((void *)buff->addr, buff->bytes_per_line * SIZE_Y);
	return (buff);
}

void	render_frame(t_param *p)
{
	static int	cur_buff;
	t_image		*buff;
	int 		ret;
	
	buff = p->bufs[cur_buff];
	ft_bzero(buff->addr, buff->bytes_per_line * SIZE_Y);
	render_map(p, buff);
//	printf("address of the current buff struct: %p\n", buff);
//	printf("address of the image inside the struct:%p\n", buff->img);
//	printf("address of the addr inside the image inside the struct:%p\n", buff->addr);
	ret = mlx_put_image_to_window(p->mlx, p->win, buff->img, 0, 0);
	cur_buff = (cur_buff == 0);
}

int	main(int ac, char **av)
{
	t_param		params;
	t_image		buff1;
	t_image		buff2;

	read_params(ac, av, &params);
	params.mlx = mlx_init();
	params.bufs[0] = init_buff(params.mlx, &buff1);
	params.bufs[1] = init_buff(params.mlx, &buff2);
	params.win = mlx_new_window(params.mlx, SIZE_X, SIZE_Y, av[1]);
	params.scale = DEFAULT_SCALE;
	params.magnitude = DEFAULT_MAGNITUDE;
	params.margin.x = SIZE_X / 2;
	params.margin.y = 50;
//	printf("address of the mlx pointer %p\naddress of the win pointer %p\n", params.mlx, params.win);
	render_frame(&params);
	mlx_loop(params.mlx);
	return (0);
}
