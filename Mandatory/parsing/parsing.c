/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:26 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/15 14:46:46 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_arg_ber(char  *av, t_init init)
{
	int len;

	len = ft_strlen(av);
	init.i = init.j - 4;
	if (len < 4)
		return (1);
	return (ft_strncmp(&av[len - 4], ".ber", 5));
}

void	ft_read_file_to_array(int fd,t_init *init, t_tab *tab)
{
	char	*final;
	char	*gnl_result;
	char 	*tmp;

	final = ft_calloc(1, 1);
	if (final == 0)
		return ;
	gnl_result = get_next_line(fd);
	while (gnl_result != 0)
	{
		tmp = ft_strjoin(final, gnl_result);
		free(final);
		free(gnl_result);
		final = tmp; // tmp et str1 meme adresse
		gnl_result = get_next_line(fd);
	}
	tab->str = ft_split(final, '\n');
	init->size_map = ft_strlen_map(tab);
	free(final);
}
void	ft_check(t_init *init, t_tab *tab)
{
	int	wall;
	
	wall = 0;
	init->i = 0;
	init->j = 0;
	while (init->i < init->size_map)
	{
		if (init->i == 0 || init->i == init->size_map)
		{
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
		init->i++;
	}
	init->error = 1;
	
}

int	parsing(char **av, t_init *init, t_tab *tab)
{
	int		fd;

	init->verif = verif_arg_ber(av[1] , *init);
	if (init->verif != 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	ft_read_file_to_array(fd, init, tab);
	ft_check(init, tab);
	if (init->error == 0)
	{
		ft_free(init->size_map, tab->str);
		close(fd);
		return (0);
	}
	int	i = 0;
	while (tab->str[i])
	{
		ft_printf("%s\n", tab->str[i]);
		i++;
	}
	ft_free(init->size_map, tab->str);
	close(fd);
	return (0);
}
