/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:46:45 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:37:34 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getheight(t_fdf *tab)
{
	int		fd;
	char	*str;
	int		i;
	int		result;

	fd = open(tab->ag[1], O_RDONLY, 0777);
	i = 0;
	result = get_next_line(fd, &str);
	while (result > 0)
	{
		i++;
		free(str);
		result = get_next_line(fd, &str);
	}
	if (result == 0)
		free(str);
	close(fd);
	return (i);
}

int	getwidth(t_fdf *tab)
{
	int		fd;
	char	**s_str;
	int		i;
	char	*gnl;

	fd = open(tab->ag[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(-1);
	if (get_next_line(fd, &gnl) <= 0)
		exit(-1);
	s_str = ft_split(gnl, ' ');
	i = 0;
	if (s_str == NULL)
		exit(-1);
	while (s_str[i])
		i++;
	ft_free_tab(s_str);
	free(gnl);
	close(fd);
	return (i);
}

int	**mallocfile(t_fdf *tab)
{
	int	**res;
	int	i;

	tab->width = getwidth(tab);
	tab->height = getheight(tab);
	res = malloc(sizeof(int *) * tab->height);
	if (!res)
		exit(-1);
	i = 0;
	while (i < tab->height)
	{
		res[i] = malloc(sizeof(int) * tab->width);
		if (!res[i])
			exit(-1);
		i++;
	}
	return (res);
}

static void	fill_row(t_fdf *tab, char *line, int row)
{
	char	**parts;
	int		i;

	parts = ft_split(line, ' ');
	i = 0;
	while (i < tab->width)
	{
		tab->map[row][i] = ft_atoi(parts[i]);
		i++;
	}
	ft_free_tab(parts);
}

void	readfile(t_fdf *tab)
{
	int		fd;
	int		row;
	int		result;
	char	*str;

	tab->map = mallocfile(tab);
	fd = open(tab->ag[1], O_RDONLY);
	result = get_next_line(fd, &str);
	row = 0;
	while (result > 0)
	{
		fill_row(tab, str, row);
		free(str);
		result = get_next_line(fd, &str);
		row++;
	}
	if (result == 0)
		free(str);
	close(fd);
}
