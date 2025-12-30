/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:12:06 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/13 12:34:01 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*vmeste;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	vmeste = malloc(sizeof(char) * (a + b + 1));
	if (!vmeste)
		return (NULL);
	ft_memmove(vmeste, s1, a);
	ft_memmove(vmeste + a, s2, b);
	vmeste[a + b] = '\0';
	return (vmeste);
}
