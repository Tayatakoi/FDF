/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:46:20 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:22:26 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	projection(float *x, float *y, int *z, t_fdf *tab)
{
	*z = tab->map[(int)*y][(int)*x] * tab->zoom * tab->h_view;
	*x *= tab->zoom;
	*y *= tab->zoom;
	rotate_point(x, y, tab->rotation);
	if (tab->projection == false)
		to_isometric(x, y, *z);
	else
	{
		*x = *x + 0.5 * cos(-1) * *z;
		*y = *y + 0.5 * sin(-1) * *z;
	}
}

void	put_pxl(t_fdf *tab, int x, int y, int color)
{
	int		i;

	i = (x * tab->data.pixel_bits / 8) + (y * tab->data.line_bytes);
	tab->data.img[i] = color;
	tab->data.img[++i] = color >> 8;
	tab->data.img[++i] = color >> 16;
}

static void	shift_points(float *x0, float *y0, int *z0, t_fdf *tab)
{
	projection(x0, y0, z0, tab);
	*x0 += tab->h_move;
	*y0 += tab->v_move;
}

void	trace_line(float x0, float y0, t_fdf *tab)
{
	int		z0;
	int		z1;
	float	x_step;
	float	y_step;
	int		max;

	shift_points(&x0, &y0, &z0, tab);
	projection(&tab->x1, &tab->y1, &z1, tab);
	tab->x1 += tab->h_move;
	tab->y1 += tab->v_move;
	x_step = tab->x1 - x0;
	y_step = tab->y1 - y0;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x0 - tab->x1) || (int)(y0 - tab->y1))
	{
		if (x0 < 1000 && y0 < 800 && x0 > 0 && y0 > 0)
			put_pxl(tab, x0, y0, fade(find_max(z0, z1)));
		x0 += x_step;
		y0 += y_step;
	}
}

void	tracing(t_fdf *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->height)
	{
		j = 0;
		while (j < tab->width)
		{
			if (j < tab->width - 1)
			{
				tab->x1 = j + 1;
				tab->y1 = i;
				trace_line(j, i, tab);
			}
			if (i < tab->height - 1)
			{
				tab->x1 = j;
				tab->y1 = i + 1;
				trace_line(j, i, tab);
			}
			j++;
		}
		i++;
	}
}
