/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:01:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/21 18:38:28 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_init *init)
{
	mlx_loop_end(init->mlx);
	return (0);
}

void	ft_wall(t_init *init)
{
	init->i = 0;
	init->j = 0;
	init->pixel_ver = 0;
	init->pixel_hor = 0;
	while (init->i < init->size_map_vertical + 1)
	{
		while (init->j < init->size_map_horizontal + 1)
		{
			if (init->str[init->i][init->j] == '1')
			{
				init->img_wall_top = mlx_xpm_file_to_image(init->mlx, "picture/wall1.xpm", &init->img_width, &init->img_height);
				if (!init->img_wall_top)
    				return ;
				mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_top, init->pixel_hor, init->pixel_ver);
			}
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
	init->mlx_win = mlx_new_window(init->mlx, 1080, 1080, "Hello");
	if (!init->mlx_win)
		return ;
	ft_wall(init);
}
