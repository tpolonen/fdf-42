/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:12:10 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/03 12:07:20 by tpolonen         ###   ########.fr       */
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
	int			rows;
	t_param		*p;

	p = (t_param *) params;
	ft_putendl(msg);
	free_map(&(p->map), &(p->cols), p->map_height);
	system("leaks fdf");
	exit(0);
}

int	event_keydown(int keycode, void *params)
{
	int	ret;
	t_param *p;

	p = (t_param *) params;
	ret = 0;
	if ((keycode > 122 && keycode < 127) || 
			(keycode >= 0 && keycode < 3) || keycode == 13)
		ret = handle_cam(keycode, p);
	if (keycode == KEY_TAB)
	{
		ret = 1;
		p->cur_proj = (p->cur_proj + 1) % PROJ_AMOUNT;
	}
	if (keycode == 53)
		handle_exit("Closing down...", p);
	if (ret)
		render_frame(p);
	return (keycode);
}
