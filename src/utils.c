/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:46:39 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:40:04 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_free_tab_of_int(int **tab, int height)
{
	int	row;

	if (!tab)
		return ;
	row = 0;
	while (row < height)
	{
		free(tab[row]);
		row++;
	}
	free(tab);
}
