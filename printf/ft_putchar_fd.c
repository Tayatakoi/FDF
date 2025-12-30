/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:41:57 by samamaev          #+#    #+#             */
/*   Updated: 2025/08/24 19:45:54 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar_fd(char c, int fd, int *count)
{
	int	ret;

	ret = write(fd, &c, 1);
	if (ft_handling(count, ret) == -1)
		return (-1);
	return (1);
}
