/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:24:21 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:24:22 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

void	rotate_point(float *x, float *y, float angle)
{
	float	old_x;
	float	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - 500) * cos(angle) - (old_y - 400) * sin(angle);
	*y = (old_x - 500) * sin(angle) + (old_y - 400) * cos(angle);
}

void	to_isometric(float *x, float *y, int z)
{
	float	x0;
	float	y0;

	x0 = *x;
	y0 = *y;
	*x = (x0 - y0) * cos(0.8);
	*y = (x0 + y0) * sin(0.8) - z;
}
