/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:26 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/14 12:58:26 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_arg(char  **av, t_init init)
{
	init.j = ft_strlen(av[1]);
	init.i = init.j - 4;
	while (init.i < init.j)
	{
		if
	}
}

int	parsing(char **av, t_init *init)
{
	verif_arg(av , *init);
	return (0);
}