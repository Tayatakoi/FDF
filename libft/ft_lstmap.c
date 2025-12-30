/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:58:54 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/12 14:59:01 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*uzel;
	t_list	*header;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	header = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		uzel = malloc(sizeof(t_list));
		if (!uzel)
		{
			del(new_content);
			ft_lstclear(&header, del);
			return (NULL);
		}
		uzel -> content = new_content;
		uzel->next = NULL;
		ft_lstadd_back(&header, uzel);
		lst = lst -> next;
	}
	return (header);
}
