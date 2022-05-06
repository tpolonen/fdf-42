/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:03:05 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/06 17:53:10 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_params(int ac, char **av, t_param *params)
{
	if (ac == 2)
	{
		params->color = DEFAULT_COLOR;
		read_file(av[1], params);
	}
	else if (ac == 5)
	{
		params->color = rgb_to_uint((unsigned char)ft_atoi(av[2]),
				(unsigned char)ft_atoi(av[3]),
				(unsigned char)ft_atoi(av[4]));
		read_file(av[1], params);
	}
	else
	{
		ft_putendl("Invalid args: expected filename and [opt.] RGB values");
		exit(1);
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
	t_image		*buff;
	int			ret;

	buff = p->bufs[p->cur_buf];
	ft_bzero(buff->addr, buff->bytes_per_line * SIZE_Y);
	render_map(p);
	ret = mlx_put_image_to_window(p->mlx, p->win, buff->img, 0, 0);
	p->cur_buf = (p->cur_buf == 0);
	if (!p->hide_text)
		put_instructions(p);
}

static void	init_params(t_param *params)
{	
	params->map = NULL;
	params->cols = NULL;
	params->scale = DEFAULT_SCALE;
	params->magnitude = DEFAULT_MAGNITUDE;
	params->margin.x = SIZE_X / 2;
	params->margin.y = 50;
	params->cur_buf = 0;
}

int	main(int ac, char **av)
{
	t_param		params;
	t_image		buff1;
	t_image		buff2;

	init_params(&params);
	read_params(ac, av, &params);
	params.mlx = mlx_init();
	if (!params.mlx)
		handle_exit("Couldn't initialize MLX-library.", NULL);
	params.bufs[0] = init_buff(params.mlx, &buff1);
	params.bufs[1] = init_buff(params.mlx, &buff2);
	params.win = mlx_new_window(params.mlx, SIZE_X, SIZE_Y, "fdf");
	load_projections(params.projs);
	render_frame(&params);
	mlx_hook(params.win, 2, 0, event_keydown, (void *)&params);
	mlx_hook(params.win, 17, 0, event_destroy, (void *)&params);
	mlx_loop(params.mlx);
	return (0);
}
