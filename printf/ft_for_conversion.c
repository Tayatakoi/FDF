/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:58:16 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/30 23:51:33 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_for_conversion(char c, va_list args, int *count)
{
	if (c == 'c')
		return (pf_putchar_fd(va_arg(args, int), 1, count));
	else if (c == 's')
		return (pf_putstr_fd(va_arg(args, char *), 1, count));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(args, count));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *), count));
	else if (c == 'u')
		return (ft_print_unsigned(args, count));
	else if (c == 'x')
		return (ft_print_hex(args, 1, count));
	else if (c == 'X')
		return (ft_print_hex(args, 0, count));
	else if (c == '%')
		return (pf_putchar_fd('%', 1, count));
	return (0);
}
