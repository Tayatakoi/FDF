/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:15:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/12 14:59:16 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*uzel;

	uzel = malloc(sizeof(t_list));
	if (!uzel)
		return (0);
	uzel -> content = content;
	uzel -> next = NULL;
	return (uzel);
}
