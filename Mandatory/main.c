/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:27 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/14 12:54:10 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_init *init;

    if (ac != 2)
        return (0);
    init = malloc(sizeof(t_init));
	if (init == NULL)
		return (0);
    init->parsing = parsing(av, init);
    if (init->parsing == 0)
        return ft_free_structure(init);
    return (0);
}