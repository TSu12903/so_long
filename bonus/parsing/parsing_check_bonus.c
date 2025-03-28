/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:35:57 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/27 16:12:34 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_wall(t_init *init)
{
	if (init->i == 0 || init->i == init->size_map_vertical)
	{
		init->j = 0;
		while (init->str[init->i][init->j])
		{
			if (init->str[init->i][init->j] != '1')
			{
				init->error = 0;
				return ;
			}
			init->j++;
		}
	}
	else
	{
		if (init->str[init->i][0] != '1'
			|| init->str[init->i][init->size_map_horizontal] != '1')
		{
			init->error = 0;
			return ;
		}
	}
}

void	ft_check_rectangle(t_init *init)
{
	init->verif = ft_strlen_map_h(init->k, init);
	if (init->size_map_horizontal != init->verif)
	{
		init->error = 0;
		return ;
	}
	init->k++;
}

void	ft_check_consumable(t_init *init, t_point *start)
{
	init->j = 0;
	while (init->str[init->i][init->j])
	{
		if (init->str[init->i][init->j] == 'E')
			init->exit++;
		if (init->str[init->i][init->j] == 'P')
		{
			start->y = init->i;
			start->x = init->j;
			init->start++;
		}
		if (init->str[init->i][init->j] == 'C')
			init->item++;
		if (init->str[init->i][init->j] != 'C'
		&& init->str[init->i][init->j] != 'P'
			&& init->str[init->i][init->j] != 'E'
				&& init->str[init->i][init->j] != '1'
					&& init->str[init->i][init->j] != '0')
		{
			init->error = 0;
			return ;
		}
		init->j++;
	}
}

void	ft_check(t_init *init, t_point *start)
{
	int	wall;

	init->i = 0;
	init->j = 0;
	init->k = 0;
	while (init->i < init->size_map_vertical + 1)
	{
		wall = ft_strlen(init->str[init->i]);
		if ((wall - 1) != init->size_map_horizontal)
		{
			init->error = 0;
			return ;
		}
		ft_check_rectangle(init);
		ft_check_wall(init);
		ft_check_consumable(init, start);
		if (init->error == 0)
			return ;
		init->i++;
	}
	if (init->exit != 1 || init->start != 1 || init->item < 1)
	{
		init->error = 0;
		return ;
	}
}
