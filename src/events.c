/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:12:10 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/02 16:03:59 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	clamp_double(double d, double min, double max)
{
	if (d < min)
		return (min);
	if (d > max)
		return (max);
	return (d);
}

static int	handle_cam(int keycode, t_param *params)
{
	if (keycode == KEY_W)
		params->margin.y += 10.0;
	if (keycode == KEY_A)
		params->margin.x += 10.0;
	if (keycode == KEY_S)
		params->margin.y -= 10.0;
	if (keycode == KEY_D)
		params->margin.x -= 10.0;
	if (keycode == KEY_UP)
		params->magnitude = clamp_double(params->magnitude + 0.05, 0.05, 2.00);
	if (keycode == KEY_DOWN)
		params->magnitude = clamp_double(params->magnitude - 0.05, 0.05, 2.00);
	if (keycode == KEY_LEFT)
		params->scale = clamp_double(params->scale + 1.00, 1.00, 60.00);
	if (keycode == KEY_RIGHT)
		params->scale = clamp_double(params->scale - 1.00, 1.00, 60.00);
	return (1);
}

void	handle_exit(char *msg, void *params)
{
	ft_putendl(msg);
	// probably should free all allocated memory, params contains all(?)
	// *mlx, *win, *bufs[2]->two t_image structs with *img pointer,
	// **map, *cols
	system("leaks fdf");
	exit(0);
}

// what's missing?
// 1. switch projection (tab)
int	event_keydown(int keycode, void *params)
{
	int	ret;

	printf("Keycode: %d\n", keycode);

	ret = 0;
	if (keycode > 122 && keycode < 127)
		ret = handle_cam(keycode, (t_param *) params);
	if ((keycode >= 0 && keycode < 3) || keycode == 13)
		ret = handle_cam(keycode, (t_param *) params);
	if (keycode == 53)
		handle_exit("Closing down...", (t_param *) params);
	if (ret)
		render_frame((t_param *) params);
	return (keycode);
}
