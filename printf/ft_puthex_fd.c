/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:14:44 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/30 23:54:28 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned long n, int fd, int lowercase, int *count)
{
	char	*base;

	if (lowercase == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (ft_puthex_fd(n / 16, fd, lowercase, count) == -1)
			return (-1);
	}
	if (pf_putchar_fd(base[n % 16], fd, count) == -1)
		return (-1);
	return (0);
}
