/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:10:00 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:49:06 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(t_fdf *tab, int color)
{
	int	x;
	int	y;

	y = 0;
	while (++y < 800)
	{
		x = 0;
		while (++x < 1000)
			put_pxl(tab, x, y, color);
	}
}

void	pannel(t_fdf *tab)
{
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 10, 0xFFFFFF, "<< COMMANDS >>");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 30, 0xFFFFFF, "W-Move up");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 50, 0xFFFFFF, "S-Move down");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 70, 0xFFFFFF, "A-Move left");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 90, 0xFFFFFF, "D-Move right");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 110, 0xFFFFFF, "R-Depth up");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 130, 0xFFFFFF, "F-Depth down");
}
