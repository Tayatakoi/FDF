/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:32:49 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/31 00:00:35 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		pf_putnbr_fd(long n, int fd, int *count);
int		pf_putchar_fd(char c, int fd, int *count);
int		ft_print_pointer(void *p, int *count);
int		ft_for_conversion(char c, va_list args, int *count);
int		ft_print_int(va_list args, int *count);
int		ft_printf(const char *s, ...);
int		ft_print_unsigned(va_list args, int *count);
int		pf_putstr_fd(char *s, int fd, int *count);
int		ft_print_hex(va_list args, int lowercase, int *count);
int		ft_handling(int *count, int s);
int		ft_puthex_fd(unsigned long n, int fd, int lowercase, int *count);

#endif