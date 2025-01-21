/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:14:34 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/21 13:27:13 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_free_structure(t_init *init)
{
	if (init)
		free(init);
	return (0);
}

int	ft_free_structure_windows(t_init *init)
{
	if (init->mlx && init)
		free(init->mlx);
	if (init)
		free(init);
	return (0);	
}

void    ft_free(int i, char **str)
{
	while(i  + 1 > 0 )
	{
		free(str[i]);
		i--;
	}
	free(str);
}

int	ft_strlen_map_v(t_init *tab)
{
	int	i;

	i = 0;
	while (tab->str[i])
		i++;
	i--;
	return (i);
}

int	ft_strlen_map_h(int j, t_init *tab)
{
	int	i;

	i = 0;
	while (tab->str[j][i])
		i++;
	i--;
	return (i);
}
