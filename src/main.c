/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:46:54 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:46:27 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_event(t_fdf *tab)
{
	if (tab->img)
		mlx_destroy_image(tab->p_mlx, tab->img);
	mlx_destroy_display(tab->p_mlx);
	free(tab->p_mlx);
	ft_free_tab_of_int(tab->map, tab->height);
	free(tab);
	exit(0);
}

void	show_map(t_fdf *tab)
{
	if (tab->img)
		mlx_destroy_image(tab->p_mlx, tab->img);
	mlx_clear_window(tab->p_mlx, tab->p_win);
	tab->img = mlx_new_image(tab->p_mlx, 1000, 800);
	tab->data.img = mlx_get_data_addr(tab->img, &tab->data.pixel_bits,
			&tab->data.line_bytes, &tab->data.endian);
	draw_background(tab, 0x181C26);
	tracing(tab);
	mlx_put_image_to_window(tab->p_mlx, tab->p_win, tab->img, 0, 0);
	pannel(tab);
}

int	event(int key, t_fdf *tab)
{
	if (key == 65307)
	{
		mlx_destroy_window(tab->p_mlx, tab->p_win);
		if (tab->img)
			mlx_destroy_image(tab->p_mlx, tab->img);
		mlx_destroy_display(tab->p_mlx);
		free(tab->p_mlx);
		ft_free_tab_of_int(tab->map, tab->height);
		free(tab);
		exit(0);
	}
	if (key == 97)
		tab->h_move += 20;
	if (key == 100)
		tab->h_move -= 20;
	if (key == 119)
		tab->v_move += 20;
	if (key == 115)
		tab->v_move -= 20;
	if (key == 114)
		tab->h_view += 0.01;
	if (key == 102)
		tab->h_view -= 0.01;
	show_map(tab);
	return (0);
}

int	main(int ac, char **ag)
{
	t_fdf	*tab;

	if (ac != 2)
		exit(-1);
	tab = malloc(sizeof(t_fdf));
	if (!tab)
		exit(-1);
	tab->h_view = 0.01;
	tab->h_move = 500;
	tab->v_move = 50;
	tab->ag = ag;
	tab->img = NULL;
	tab->p_mlx = mlx_init();
	tab->map = NULL;
	readfile(tab);
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 800, ag[1]);
	tab->zoom = find_max(1000 / tab->width, 2);
	show_map(tab);
	mlx_do_key_autorepeaton(tab->p_mlx);
	mlx_hook(tab->p_win, 2, (1L << 0), event, tab);
	mlx_hook(tab->p_win, 17, 0, close_event, tab);
	mlx_loop(tab->p_mlx);
}
