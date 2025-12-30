/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:44:28 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/13 19:18:25 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(char const *s, char c)
{
	int	kol;

	kol = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			kol++;
			while (*s && *s != c)
				s++;
		}
	}
	return (kol);
}

static int	len_of_substring(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	chistka(char **result, int n)
{
	while (n--)
		free(result[n]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		slova;
	int		i;

	if (!s)
		return (NULL);
	slova = count_substrings(s, c);
	result = malloc(sizeof(char *) * (slova + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < slova)
	{
		while (*s == c)
			s++;
		result[i] = ft_substr(s, 0, len_of_substring(s, c));
		if (!result[i])
			return (chistka(result, i), NULL);
		s += len_of_substring(s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
