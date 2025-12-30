/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/31 00:27:05 by samamaev         ###   ########.fr       */
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

void	copy_content(char *next_str, t_gnl_list *list, int *s)
{
	int	i;

	i = 0;
	while (list->content[i])
	{
		if (list->content[i] == '\n')
		{
			next_str[(*s)++] = '\n';
			return ;
		}
		next_str[(*s)++] = list->content[i++];
	}
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


