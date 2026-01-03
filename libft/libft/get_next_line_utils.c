/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2026/01/03 22:04:02 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*find_last_node(t_gnl_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	find_newline(t_gnl_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	len_to_newline(t_gnl_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	chistka(t_gnl_list **list)
{
	t_gnl_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

char	*extract_line(t_gnl_list *list)
{
	char	*next;
	int		len;
	int		k;
	char	*s;

	len = len_to_newline(list);
	next = malloc(len + 1);
	if (!next)
		return (NULL);
	k = 0;
	while (list)
	{
		s = list->content;
		while (*s && *s != '\n')
			next[k++] = *s++;
		if (*s == '\n')
		{
			next[k++] = '\n';
			next[k] = '\0';
			return (next);
		}
		list = list->next;
	}
	next[k] = '\0';
	return (next);
}
