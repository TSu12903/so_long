/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:16:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/22 17:17:56 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_draw_wall(t_init *init)
{
	if (init->str[init->i][init->j] == '1')
	{
		init->img_wall_top = mlx_xpm_file_to_image(init->mlx, "picture/wall1.xpm", &init->img_width, &init->img_height);
		if (!init->img_wall_top)
			return ;
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_top, init->pixel_hor, init->pixel_ver);
	}
	if (init->str[init->i][init->j] == '0')
	{
		init->img_wall_ground = mlx_xpm_file_to_image(init->mlx, "picture/ground.xpm", &init->img_width, &init->img_height);
		if (!init->img_wall_ground)
			return ;
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_ground, init->pixel_hor, init->pixel_ver);
	}
}

void	ft_draw_key(t_init *init)
{
	if (init->str[init->i][init->j] == 'C')
	{
		init->img_wall_key = mlx_xpm_file_to_image(init->mlx, "picture/key.xpm", &init->img_width, &init->img_height);
		if (!init->img_wall_key)
			return ;
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_key, init->pixel_hor, init->pixel_ver);
	}
}

void	ft_draw_prisoner(t_init *init)
{
	if (init->str[init->i][init->j] == 'P')
	{
		init->img_wall_prisoner = mlx_xpm_file_to_image(init->mlx, "picture/prisoner.xpm", &init->img_width, &init->img_height);
		if (!init->img_wall_prisoner)
			return ;
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_prisoner, init->pixel_hor, init->pixel_ver);
	}
	if (init->str[init->i][init->j] == 'E')
	{
		init->img_wall_door = mlx_xpm_file_to_image(init->mlx, "picture/lock.xpm", &init->img_width, &init->img_height);
		if (!init->img_wall_door)
			return ;
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_door, init->pixel_hor, init->pixel_ver);
	}
}
