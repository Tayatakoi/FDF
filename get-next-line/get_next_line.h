/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:34:36 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/31 00:35:24 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_gnl_list
{
	char			*content;
	struct s_gnl_list   *next;
}	t_gnl_list;
void	append_node(t_gnl_list **list, char *buffer);
t_gnl_list	*find_last_node(t_gnl_list *list);
int		find_newline(t_gnl_list *list);
char	*extract_line(t_gnl_list *list);
int		len_to_newline(t_gnl_list *list);
void	chistka(t_gnl_list **list);
void	copy_content(char *next_str, t_gnl_list *list, int *k);
int		create_list(t_gnl_list **list, int fd);
void	polish_list(t_gnl_list **list);
int		get_next_line(int fd, char **line);

#endif
