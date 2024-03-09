/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:41:01 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/03/04 16:22:46 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_mandel(char **argv)
{
	t_params	m;

	m.x_min = -4;
	m.x_max = 4;
	m.y_min = -2.5;
	m.y_max = 2.5;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		m.type = 'm';
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		m.type = 'j';
		m.cx = ft_atod(argv[2]);
		m.cy = ft_atod(argv[3]);
	}
	else
		m.type = 's';
	return (m);
}

static unsigned int	calculate_color(int iterations)
{
	unsigned int	color;
	double			t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (iterations < MAX_ITERATIONS)
	{
		t = (double)iterations / MAX_ITERATIONS;
		r = (unsigned char)(0xFF0000 * t);
		g = (unsigned char)(512 * t);
		b = (unsigned char)((0xADD8E6 >> 4) * (1 - t));
		color = (r << 16) | (g << 28) | b;
	}
	else
		color = 0xFF0000;
	return (color);
}

static void	render_temp(t_params *m, double zoom)
{
	double			temp_x;
	double			temp_y;
	unsigned int	color;
	int				iterations;

	while (m->x < m->g_img->width)
	{
		temp_x = m->x_min + (m->x / (double)m->g_img->width)
			* (m->x_max - m->x_min) * zoom;
		temp_y = m->y_min + (m->y / (double)m->g_img->height)
			* (m->y_max - m->y_min) * zoom;
		if (m->type == 'j')
			iterations = julia(temp_x, temp_y, m->cx, m->cy);
		else if (m->type == 'm')
			iterations = mandelbrot(temp_x, temp_y);
		else
			iterations = burning_ship(temp_x, temp_y);
		color = calculate_color(iterations);
		mlx_put_pixel(m->g_img, m->x, m->y, color);
		m->x++;
	}
}

void	render(t_params m, double zoom)
{
	m.y = 0;
	while (m.y < m.g_img->height)
	{
		m.x = 0;
		render_temp(&m, zoom);
		m.y++;
	}
}
