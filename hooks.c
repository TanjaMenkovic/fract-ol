/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:50:35 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/03/04 10:30:45 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_params *m)
{
	double	temp_x_range;
	double	temp_y_range;

	temp_x_range = (m->x_max - m->x_min) / 5;
	temp_y_range = (m->y_max - m->y_min) / 5;
	m->x_min += temp_x_range / 1.5;
	m->x_max -= temp_x_range / 1.5;
	m->y_min += temp_y_range / 1.5;
	m->y_max -= temp_y_range / 1.5;
}

void	zoom_out(t_params *m)
{
	double	temp_x_range;
	double	temp_y_range;

	temp_x_range = (m->x_max - m->x_min) / 5;
	temp_y_range = (m->y_max - m->y_min) / 5;
	m->x_min -= temp_x_range * 1.5;
	m->x_max += temp_x_range * 1.5;
	m->y_min -= temp_y_range * 1.5;
	m->y_max += temp_y_range * 1.5;
}

static void	key_press_temp(t_params *m, char s)
{
	if (s == '+')
	{
		m->y_min += (m->y_max - m->y_min) / 50;
		m->y_max += (m->y_max - m->y_min) / 50;
	}
	else
	{
		m->y_min -= (m->y_max - m->y_min) / 50;
		m->y_max -= (m->y_max - m->y_min) / 50;
	}
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_params	*m;

	m = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(m->mlx);
	else if (keydata.key == MLX_KEY_DOWN)
		key_press_temp(m, '+');
	else if (keydata.key == MLX_KEY_UP)
		key_press_temp(m, '-');
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		m->x_min += (m->x_max - m->x_min) / 50;
		m->x_max += (m->x_max - m->x_min) / 50;
	}
	else if (keydata.key == MLX_KEY_LEFT)
	{
		m->x_min -= (m->x_max - m->x_min) / 50;
		m->x_max -= (m->x_max - m->x_min) / 50;
	}
	render(*m, 1);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_params	*m;

	m = (t_params *)param;
	(void)xdelta;
	if (ydelta > 0)
		zoom_in(m);
	else if (ydelta < 0)
		zoom_out(m);
	render(*m, 1);
}
