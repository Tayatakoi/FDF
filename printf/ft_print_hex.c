/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:23:18 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/24 20:20:57 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list args, int lowercase, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (ft_puthex_fd((unsigned long)n, 1, lowercase, count) == -1)
		return (-1);
	return (0);
}
