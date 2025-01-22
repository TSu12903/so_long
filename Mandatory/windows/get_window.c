/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:01:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/22 18:04:24 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_init *init)
{
	mlx_loop_end(init->mlx);
	return (0);
}

void ft_load_images(t_init *init)
{
    init->img_wall_top = mlx_xpm_file_to_image(init->mlx, "picture/wall1.xpm", &init->img_width, &init->img_height);
    init->img_wall_ground = mlx_xpm_file_to_image(init->mlx, "picture/ground.xpm", &init->img_width, &init->img_height);
    init->img_wall_key = mlx_xpm_file_to_image(init->mlx, "picture/key.xpm", &init->img_width, &init->img_height);
    init->img_wall_prisoner = mlx_xpm_file_to_image(init->mlx, "picture/prisoner.xpm", &init->img_width, &init->img_height);
    init->img_wall_door = mlx_xpm_file_to_image(init->mlx, "picture/lock.xpm", &init->img_width, &init->img_height);

    if (!init->img_wall_top || !init->img_wall_ground || !init->img_wall_key || 
        !init->img_wall_prisoner || !init->img_wall_door)
    {
        ft_destroy(init);
        exit(EXIT_FAILURE);
    }
}

void	ft_draw_map(t_init *init)
{
	init->i = 0;
	init->j = 0;
	init->pixel_ver = 0;
	init->pixel_hor = 0;
	while (init->i < init->size_map_vertical + 1)
	{
		while (init->j < init->size_map_horizontal + 1)
		{
			ft_draw(init);
			init->j++;
			init->pixel_hor = 40 * init->j;
		}
		init->j = 0;
		init->pixel_hor = 0;
		init->i++;
		init->pixel_ver = 40 * init->i;
	}
}

void   start_window(t_init *init)
{
	init->img_width = 40;
	init->img_height = 40;
	init->mlx = mlx_init();
	if (!init->mlx)
		return ;
	init->mlx_win = mlx_new_window(init->mlx, 1080, 1080, "Freedom Quest");
	if (!init->mlx_win)
		return ;
	ft_load_images(init);
	ft_draw_map(init);
}
