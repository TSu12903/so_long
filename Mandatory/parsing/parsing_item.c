/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:36:12 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/16 18:46:18 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_init *init, t_point start)
{
	if (init->str[start.y][start.x] == '1')
		return ;
	init->str[start.y][start.x] = '1';
	flood_fill(init, (t_point){start.y, start.x + 1});
	flood_fill(init, (t_point){start.y, start.x - 1});
	flood_fill(init, (t_point){start.y + 1, start.x});
	flood_fill(init, (t_point){start.y - 1, start.x});
	return ;
}

void	ft_check_items_acces(t_init *init, t_point *start)
{
	if (init->error == 0)
		return ;
	flood_fill(init, *start);
	init->i = 0;
	init->j = 0;
	while (init->i < init->size_map_vertical + 1)
	{
		while (init->j < init->size_map_horizontal + 1)
		{
			if (init->str[init->i][init->j] == 'C'
			|| init->str[init->i][init->j] == 'E'
			|| init->str[init->i][init->j] == 'P')
			{
				init->error = 0;
				return ;
			}
			init->j++;
		}
		init->j = 0;
		init->i++;
	}
}
