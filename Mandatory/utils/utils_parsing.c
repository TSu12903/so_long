/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:14:34 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/14 18:32:02 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_free_structure(t_init *init)
{
    free(init);
    return (0);
}

void    ft_free(int i, char **str)
{
    while(i  + 1 > 0 )
    {
        free(str[i]);
        i--;
    }
}