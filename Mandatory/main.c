/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:27 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/20 17:44:28 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_init	*init;
	t_point	start;

	if (ac != 2)
		return (0);
	init = malloc(sizeof(t_init));
	if (init == NULL)
		return (0);
	ft_init(init);
	init->parsing = parsing(av, init, &start);
	if (init->parsing == 0)
		return (ft_free_structure(init));
	start_window(init);
	mlx_hook(init->mlx_win, 17, 1L<<0, ft_close, init);
	mlx_loop(init->mlx);
	mlx_destroy_window(init->mlx,init->mlx_win);
	mlx_destroy_display(init->mlx);
	ft_free(init->size_map_vertical, init->str);
	ft_free_structure(init);
	return (0);
}
