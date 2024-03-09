/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:51:30 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/03/02 14:51:39 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x, double y)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	iterations = 0;
	real = 0.0;
	imag = 0.0;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + x;
		imag = 2.0 * real * imag + y;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}

int	julia(double x, double y, double cx, double cy)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	real = x;
	imag = -y;
	iterations = 0;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + cx;
		imag = 2.0 * real * imag + cy;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}

int	burning_ship(double x, double y)
{
	int		iterations;
	double	real;
	double	imag;
	double	real_temp;

	iterations = 0;
	real = x;
	imag = y;
	while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0)
	{
		real_temp = real * real - imag * imag + x;
		imag = 2.0 * fabs(real * imag) + y;
		real = real_temp;
		iterations++;
	}
	return (iterations);
}
