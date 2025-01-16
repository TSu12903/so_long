/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:35:57 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/16 11:46:50 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_check_wall(t_init *init, t_tab *tab)
{
	if (init->i == 0 || init->i == init->size_map_vertical)
	{
		init->j = 0;
		while (tab->str[init->i][init->j])
		{
			if (tab->str[init->i][init->j] != '1')
			{
				init->error = 0;
				return ;
			}
			init->j++;
		}
	}
	else 
	{
		if (tab->str[init->i][0] != '1' || tab->str[init->i][init->size_map_horizontal] != '1')
		{
			init->error = 0;
			return ;
		}
	}
}

void	ft_check_rectangle(t_init *init, t_tab *tab)
{
	init->verif = ft_strlen_map_h(init->k, tab);
	if (init->size_map_horizontal != init->verif)
	{
		init->error = 0;
		return ;
	}
	init->k++;
}

void	ft_check_consumable(t_init *init, t_tab *tab)
{
	init->j = 0;
	while (tab->str[init->i][init->j])
	{
		if (tab->str[init->i][init->j] == 'E')
			init->exit++;
		if (tab->str[init->i][init->j] == 'P')
			init->start++;
		if (tab->str[init->i][init->j] == 'C')
			init->item++;
		init->j++;
	}
}

void	ft_check(t_init *init, t_tab *tab)
{
	int	wall;
	
	wall = 0;
	init->i = 0;
	init->j = 0;
	init->k = 0;
	while (init->i < init->size_map_vertical + 1)
	{
		ft_check_rectangle(init, tab);
		ft_check_wall(init, tab);
		ft_check_consumable(init, tab);
		if (init->error == 0)
			return ;
		init->i++;
	}
	if (init->exit != 1 || init->start != 1 || init->item < 1)
	{
		init->error = 0;
		return ;
	}
	init->error = 1;
}
