/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:51:00 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/03/04 16:24:00 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define MAX_ITERATIONS 800

typedef struct params
{
	mlx_image_t	*g_img;
	mlx_t		*mlx;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	uint32_t	x;
	uint32_t	y;
	double		cx;
	double		cy;
	char		type;
}	t_params;

/* errors.c */
void		error_message(char *s, char *t);
void		input_errors(int argc, char **argv);
void		setup_errors(t_params *m);

/* hooks.c */
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		zoom_in(t_params *m);
void		zoom_out(t_params *m);
void		key_press(mlx_key_data_t keydata, void *param);

/* fractals_utils.c */
void		render(t_params m, double zoom);
t_params	init_mandel(char **argv);

void		mlx_put_pixel(mlx_image_t *image, uint32_t x,
				uint32_t y, uint32_t color);

/* fractals.c */
int			mandelbrot(double x, double y);
int			julia(double x, double y, double cx, double cy);
int			burning_ship(double x, double y);

/* utils.c */
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(char *str);

#endif
