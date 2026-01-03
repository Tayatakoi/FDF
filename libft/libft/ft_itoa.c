/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:46:22 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/01 19:53:55 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nomer;
	int		negative;
	int		len;
	char	*da;

	nomer = n;
	negative = (n < 0);
	if (negative)
		nomer = -nomer;
	len = count_digits(nomer) + negative;
	da = malloc(sizeof(char) * (len + 1));
	if (!da)
		return (NULL);
	da[len] = '\0';
	while (len > 0)
	{
		len--;
		da[len] = nomer % 10 + '0';
		nomer /= 10;
		if (len == 0 && negative)
			da[0] = '-';
	}
	return (da);
}
