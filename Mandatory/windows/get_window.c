/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:01:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/20 17:44:19 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_init *init)
{
	mlx_loop_end(init->mlx);
	// mlx_clear_window(init->mlx, init->mlx_win);
	return (0);
}
	
void   start_window(t_init *init)
{
	init->mlx = mlx_init();
	if (!init->mlx)
		return ;
	init->mlx_win = mlx_new_window(init->mlx, 1920, 1080, "Hello");
	if (!init->mlx_win)
		return ;
}
