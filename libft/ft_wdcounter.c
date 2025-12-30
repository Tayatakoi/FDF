/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:27:49 by samamaev          #+#    #+#             */
/*   Updated: 2025/12/30 23:32:37 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_wdcounter(char const *str, char c)
{
    int i;
    int words;

    words = 0;
    i = 0;
    while(str[i])
    {
        while(str[i] == c && str[i] != '\0')
            i++;
        if (str[i])
            words++;
        while (str[i] != c && str[i] != '\0')
            i++;
    }
    return (words);
}
