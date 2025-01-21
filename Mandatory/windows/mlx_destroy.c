/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:25 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/21 18:57:42 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_destroy(t_init *init)
{
    mlx_hook(init->mlx_win, 17, 1L<<0, ft_close, init);
	mlx_loop(init->mlx);
	mlx_destroy_window(init->mlx,init->mlx_win);
	mlx_destroy_display(init->mlx);
    mlx_destroy_image(init->mlx, init->img_wall_top);
}