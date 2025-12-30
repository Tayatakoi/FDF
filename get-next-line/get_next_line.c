/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:33:36 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/31 00:36:05 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_gnl_list **list)
{
	t_gnl_list	*last;
	t_gnl_list	*new;
	char		*buf;
	int			i;
	int			k;

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
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	k = 0;
	while (last->content[++i])
		buf[k++] = last->content[i];
	buf[k] = '\0';
	chistka(list);
	new = malloc(sizeof(t_gnl_list));
	if (!new)
	{
		free(buf);
		return ;
	}
	new->content = buf;
	new->next = NULL;
	*list = new;
}

int	create_list(t_gnl_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!find_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (0);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			return (-1);
		}
		if (char_read == 0)
		{
			free(buf);
			return (0);
		}
		buf[char_read] = '\0';
		append_node(list, buf);
	}
	return (1);
}

char	*extract_line(t_gnl_list *list)
{
	int		str_len;
	char	*next_str;
	int		k;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	k = 0;
	while (list)
	{
		copy_content(next_str, list, &k);
		if (k > 0 && next_str[k - 1] == '\n')
		{
			next_str[k] = '\0';
			return (next_str);
		}
		list = list->next;
	}
	next_str[k] = '\0';
	return (next_str);
}

void	append_node(t_gnl_list **list, char *buffer)
{
	t_gnl_list	*new_node;
	t_gnl_list	*last_node;

	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
		return ;
	new_node->content = buffer;
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last_node = find_last_node(*list);
		last_node->next = new_node;
	}
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