/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:09:55 by samamaev          #+#    #+#             */
/*   Updated: 2025/07/29 15:12:39 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		dlina;
	char	*dest;

	dlina = 0;
	while (s1[dlina])
		dlina++;
	dest = malloc (sizeof(char) * dlina + 1);
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < dlina)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
