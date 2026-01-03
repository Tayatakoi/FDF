/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:21:30 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/01 18:39:29 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	da;

	da = n;
	if (da < 0)
	{
		ft_putchar_fd('-', fd);
		da *= -1;
	}
	if (da >= 0 && da <= 9)
		ft_putchar_fd(da + '0', fd);
	if (da > 9)
	{
		ft_putnbr_fd(da / 10, fd);
		ft_putnbr_fd(da % 10, fd);
	}
}
