/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:33:36 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:09:38 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_gnl_list	*create_new_node(char *buf)
{
	t_gnl_list	*new;

	new = malloc(sizeof(t_gnl_list));
	if (!new)
	{
		free(buf);
		return (NULL);
	}
	new->content = buf;
	new->next = NULL;
	return (new);
}

void	polish_list(t_gnl_list **list)
{
	t_gnl_list	*last;
	char		*buf;
	int			i;

	if (!list || !*list)
		return ;
	last = find_last_node(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (!last->content[i])
	{
		chistka(list);
		*list = NULL;
		return ;
	}
	buf = ft_strdup(last->content + i + 1);
	if (!buf)
		return ;
	chistka(list);
	*list = create_new_node(buf);
}

static int	append_buffer(t_gnl_list **list, int fd)
{
	int			char_read;
	char		*buf;
	t_gnl_list	*new_node;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	char_read = read(fd, buf, BUFFER_SIZE);
	if (char_read <= 0)
	{
		free(buf);
		return (-1 * (char_read < 0));
	}
	buf[char_read] = '\0';
	new_node = create_new_node(buf);
	if (!new_node)
		return (-1);
	if (!*list)
		*list = new_node;
	else
		find_last_node(*list)->next = new_node;
	return (1);
}

int	create_list(t_gnl_list **list, int fd)
{
	int	status;

	while (!find_newline(*list))
	{
		status = append_buffer(list, fd);
		if (status <= 0)
			return (status);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_list	*list = NULL;
	char				*next_line;
	int					result;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	result = create_list(&list, fd);
	if (result == -1)
	{
		chistka(&list);
		return (-1);
	}
	if (!list)
		return (0);
	next_line = extract_line(list);
	if (!next_line)
		return (-1);
	*line = next_line;
	polish_list(&list);
	if (**line == '\0')
		return (0);
	return (1);
}

// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *test;
// 	test = get_next_line(fd);
// 	while (test)
// 	{
// 		printf("%s", test);
// 		test = get_next_line(fd);	
// 	}
// 	return (0);
// }