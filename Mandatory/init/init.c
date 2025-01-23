/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:45:09 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/23 12:22:11 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_init(t_init *init)
{
	init->error = 1;
	init->exit = 0;
	init->item = 0;
	init->start = 0;
}
void	ft_init_picture(t_init *init)
{
	init->img_wall_top = NULL;
	init->img_wall_ground = NULL;
	init->img_wall_key = NULL;
	init->img_wall_prisoner = NULL;
	init->img_wall_door = NULL;
}