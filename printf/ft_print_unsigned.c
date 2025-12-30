/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:19:06 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/30 23:54:46 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putunbr_unsigned(unsigned int n, int fd, int *count)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		if (putunbr_unsigned(n / 10, fd, count) == -1)
			return (-1);
	}
	if (pf_putchar_fd((n % 10) + '0', fd, count) == -1)
		return (-1);
	i += 1;
	return (i);
}

int	ft_print_unsigned(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (putunbr_unsigned(n, 1, count) == -1)
		return (-1);
	return (0);
}
