/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:35:43 by samamaev          #+#    #+#             */
/*   Updated: 2025/07/24 22:46:34 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ln_src;
	size_t	ln_dst;
	size_t	total_len;

	ln_src = ft_strlen(src);
	ln_dst = ft_strlen(dst);
	i = 0;
	total_len = 0;
	if (dstsize > ln_dst)
		total_len = ln_dst + ln_src;
	else
		return (ln_src + dstsize);
	while (src[i] && ln_dst < dstsize -1)
		dst[ln_dst++] = src[i++];
	dst[ln_dst] = '\0';
	return (total_len);
}
