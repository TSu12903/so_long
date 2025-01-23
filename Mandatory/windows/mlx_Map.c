/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_Map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:16:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/23 19:08:15 by tcybak           ###   ########.fr       */
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
	{
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_prisoner, init->pixel_hor, init->pixel_ver);
		init->player_y = init->i;
		init->player_x = init->j;
	}
	if (init->str[init->i][init->j] == 'E')
	{
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->img_wall_door, init->pixel_hor, init->pixel_ver);
		init->exit_y = init->i;
		init->exit_x = init->j;
	}
}

void	ft_finish(t_init *init)
{
	if (init->str[init->i][init->j] == 'C')
		init->item--;
	if (init->str[init->i][init->j] == 'E' && init->item == 0)
	{
		ft_destroy(init);
		exit(0);
	}
}

void	ft_move_top_low(int keycode,t_init *init)
{
	if (keycode == 119) //w
	{
		if (init->str[init->i - 1][init->j] != '1')
		{
			init->str[init->i][init->j] = '0';
			if (init->str[init->i][init->j] == init->str[init->exit_y][init->exit_x])
				init->str[init->i][init->j] = 'E';
			init->i -= 1;
			ft_finish(init);
			init->str[init->i][init->j] = 'P';
		}
	}
	if (keycode == 115) //s
	{
		if (init->str[init->i + 1][init->j] != '1')
		{
			init->str[init->i][init->j] = '0';
			if (init->str[init->i][init->j] == init->str[init->exit_y][init->exit_x])
				init->str[init->i][init->j] = 'E';
			init->i += 1;
			ft_finish(init);
			init->str[init->i][init->j] = 'P';
		}
	}
}

int	ft_move(int keycode, t_init *init)
{
	init->i = init->player_y;
	init->j = init->player_x;
	if (keycode == 65307)
	{
		ft_destroy(init);
        exit(0);
    }
	ft_move_top_low(keycode, init);
	if (keycode == 97) //a
	{
		if (init->str[init->i][init->j - 1] != '1')
		{
			init->str[init->i][init->j] = '0';
			if (init->str[init->i][init->j] == init->str[init->exit_y][init->exit_x])
				init->str[init->i][init->j] = 'E';
			init->j -= 1;
			ft_finish(init);
			init->str[init->i][init->j] = 'P';
		}
	}
	if (keycode == 100) //d 
	{
		if (init->str[init->i][init->j + 1] != '1')
		{
			init->str[init->i][init->j] = '0';
			if (init->str[init->i][init->j] == init->str[init->exit_y][init->exit_x])
				init->str[init->i][init->j] = 'E';
			init->j += 1;
			ft_finish(init);
			init->str[init->i][init->j] = 'P';
		}
	}
	mlx_clear_window(init->mlx, init->mlx_win);
	ft_draw_map(init);
	return (1);
}
