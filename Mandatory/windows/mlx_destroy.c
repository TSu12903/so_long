/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:25 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/23 12:11:08 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_destroy(t_init *init)
{
	mlx_destroy_window(init->mlx,init->mlx_win);
	if (init->img_wall_top)
		mlx_destroy_image(init->mlx, init->img_wall_top);
	if (init->img_wall_ground)
		mlx_destroy_image(init->mlx, init->img_wall_ground);
	if (init->img_wall_key)
		mlx_destroy_image(init->mlx, init->img_wall_key);
	if (init->img_wall_prisoner)
		mlx_destroy_image(init->mlx, init->img_wall_prisoner);
	if (init->img_wall_door)
		mlx_destroy_image(init->mlx, init->img_wall_door);
	mlx_destroy_display(init->mlx);
	ft_free(init->size_map_vertical, init->str);
	ft_free_structure_windows(init);
}
