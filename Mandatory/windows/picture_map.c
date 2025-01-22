/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:16:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/22 18:00:07 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_draw(t_init *init)
{
	if (init->str[init->i][init->j] == '1')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_top, init->pixel_hor, init->pixel_ver);
	if (init->str[init->i][init->j] == '0')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_ground, init->pixel_hor, init->pixel_ver);
	if (init->str[init->i][init->j] == 'C')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_key, init->pixel_hor, init->pixel_ver);
	if (init->str[init->i][init->j] == 'P')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_prisoner, init->pixel_hor, init->pixel_ver);
	if (init->str[init->i][init->j] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_door, init->pixel_hor, init->pixel_ver);
}
