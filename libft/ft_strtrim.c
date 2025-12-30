/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:27:20 by samamaev          #+#    #+#             */
/*   Updated: 2025/07/28 22:15:28 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*bez_fegni;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && is_set(s1[first], set))
		first++;
	while (last >= first && is_set(s1[last], set))
		last--;
	if (first > last)
		return (ft_strdup(""));
	bez_fegni = malloc(sizeof(char) * ((last - first + 1) + 1));
	if (!bez_fegni)
		return (NULL);
	ft_memmove(bez_fegni, s1 + first, (last - first + 1));
	bez_fegni[last - first + 1] = '\0';
	return (bez_fegni);
}
