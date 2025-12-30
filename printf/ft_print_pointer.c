/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:05:09 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/30 23:54:08 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *p, int *count)
{
	if (!p)
	{
		if (pf_putstr_fd("0x0", 1, count) == -1)
			return (-1);
		return (0);
	}
	if (pf_putstr_fd("0x", 1, count) == -1)
		return (-1);
	return (ft_puthex_fd((unsigned long)p, 1, 1, count));
}
