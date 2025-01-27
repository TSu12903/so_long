/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:27 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/27 14:22:58 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_init	*init;
	t_point	start;

	if (ac != 2)
	{
		write(2, "Error\n argv", 10);
		return (0);
	}
	init = malloc(sizeof(t_init));
	if (init == NULL)
		return (0);
	ft_init(init);
	init->parsing = parsing(av, init, &start);
	if (init->parsing == 0)
		return (ft_free_structure(init));
	start_window(init);
	mlx_hook(init->mlx_win, 17, 0, ft_close, init);
	mlx_loop(init->mlx);
	ft_destroy(init);
	return (0);
}
