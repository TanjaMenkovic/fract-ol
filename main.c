/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:49:54 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/03/04 12:54:40 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_params	m;

	input_errors(argc, argv);
	m = init_mandel(argv);
	m.mlx = mlx_init(800, 600, "FRACTOL", true);
	m.g_img = mlx_new_image(m.mlx, 800, 600);
	if (ft_strcmp(argv[1], "mandelbrot") == 0
		|| ft_strcmp(argv[1], "julia") == 0
		|| ft_strcmp(argv[1], "ship") == 0)
		render(m, 1);
	else
		exit(EXIT_FAILURE);
	mlx_image_to_window(m.mlx, m.g_img, 0, 0);
	mlx_scroll_hook(m.mlx, &my_scrollhook, &m);
	mlx_key_hook(m.mlx, key_press, &m);
	mlx_loop(m.mlx);
	mlx_delete_image(m.mlx, m.g_img);
	mlx_terminate(m.mlx);
	return (EXIT_SUCCESS);
}
