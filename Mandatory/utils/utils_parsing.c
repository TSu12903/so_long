/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:14:34 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/15 14:32:57 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_free_structure(t_init *init, t_tab *tab)
{
	free(init);
	free(tab);
	return (0);
}

int ft_free_init(t_init *init)
{
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
int	ft_strlen_map(t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->str[i])
		i++;
	i--;
	return (i);
}