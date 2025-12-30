/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:11:52 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/13 12:40:53 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*w;
	size_t	dlina_s;

	if (!s)
		return (0);
	dlina_s = ft_strlen(s);
	if (start >= dlina_s)
		return (ft_strdup(""));
	if (len > dlina_s - start)
		len = dlina_s - start;
	w = malloc(sizeof(char) * (len + 1));
	if (!w)
		return (0);
	ft_strlcpy(w, s + start, len + 1);
	return (w);
}
