/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:45:48 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:22:26 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_p2(int key, t_fdf *tab)
{
	if (key == 112 && tab->projection == false)
		tab->projection = true;
	else if (key == 112)
		tab->projection = false;
	if (key == 114)
		tab->h_view += 0.01;
	if (key == 102)
		tab->h_view -= 0.01;
	if (key == 44)
		tab->rotation -= 0.1;
	if (key == 46)
		tab->rotation += 0.1;
}

int	fade(int h)
{
	if (h > 100)
		return (0xFFDF8D);
	if (h > 75)
		return (0xFFDE7A);
	if (h > 50)
		return (0xFFC568);
	if (h > 25)
		return (0xFD996B);
	if (h > 15)
		return (0xF7856C);
	if (h > 10)
		return (0xF06E6C);
	if (h > 5)
		return (0xD9576B);
	if (h > 0)
		return (0xA44369);
	if (h > -10)
		return (0x833F68);
	if (h > -20)
		return (0x833F68);
	if (h > -50)
		return (0x5E3C65);
	return (0x3F3A63);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	find_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	find_mod(int num)
{
	if (0 > num)
		return (-num);
	return (num);
}
