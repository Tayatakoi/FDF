/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:29:39 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/30 23:50:27 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		ret;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				return (count);
			ret = ft_for_conversion(*s, args, &count);
			if (ret == -1)
				return (-1);
		}
		else
			ret = pf_putchar_fd(*s, 1, &count);
		if (ret == -1)
			return (-1);
		s++;
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// int main(void)
// {
//     ft_printf("Hello, world!\n");
//     ft_printf("Name: %s\n", "saif");
//     ft_printf("Value: %d\n", 42);
//     ft_printf("Progress: 100%% done\n");
//     ft_printf("User: %s | Age: %d | Hex: %x\n", "Ammar", 30, 255);
//     ft_printf("This is bad %");
// 	printf("This is bad %");
// 	ft_printf("ABC %d\n", 123);
//     return (0);
// }