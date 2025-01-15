/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:27 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/15 13:19:55 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_init *init;
    t_tab   *tab;

    if (ac != 2)
        return (0);
    init = malloc(sizeof(t_init));
	if (init == NULL)
		return (0);
    tab = malloc(sizeof(t_tab));
	if (tab == NULL)
		return (ft_free_init(init));
    init->parsing = parsing(av, init, tab);
    if (init->parsing == 0)
        return ft_free_structure(init, tab);
    return (0);
}