/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:26 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/24 15:26:29 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_arg_ber(char *av, t_init init)
{
	int	len;

	len = ft_strlen(av);
	init.i = init.j - 4;
	if (len < 4)
		return (1);
	return (ft_strncmp(&av[len - 4], ".ber", 5));
}

void	ft_read_file_to_array(int fd, t_init *init)
{
	char	*final;
	char	*gnl_result;
	char	*tmp;

	init->k = 0;
	final = ft_calloc(1, 1);
	if (final == 0)
		return ;
	gnl_result = get_next_line(fd);
	while (gnl_result != 0)
	{
		tmp = ft_strjoin(final, gnl_result);
		free(final);
		free(gnl_result);
		final = tmp;
		gnl_result = get_next_line(fd);
	}
	init->str = ft_split(final, '\n');
	init->size_map_vertical = ft_strlen_map_v(init);
	init->size_map_horizontal = ft_strlen_map_h(init->k, init);
	free(final);
	close(init->fd);
}

void	ft_verif_empty_map(char **av, t_init *init)
{
	char	*gnl_result;

	init->fd = open(av[1], O_RDONLY);
	gnl_result = get_next_line(init->fd);
	if (gnl_result == 0)
	{
		free(gnl_result);
		init->error = 0;
		close(init->fd);
		return ;
	}
	while (gnl_result != 0)
	{
		free(gnl_result);
		gnl_result = get_next_line(init->fd);
	}
	free(gnl_result);
	close(init->fd);
	return ;
}

int	parsing(char **av, t_init *init, t_point *start)
{
	init->verif = verif_arg_ber(av[1], *init);
	ft_verif_empty_map(av, init);
	if (init->verif != 0 || init->error == 0)
	{
		write(2, "File Error \n", 12);
		return (0);
	}
	init->fd = open(av[1], O_RDONLY);
	ft_read_file_to_array(init->fd, init);
	ft_check(init, start);
	ft_check_items_acces(init, start);
	if (init->size_map_vertical + 1 > 30 || init->size_map_horizontal + 1 > 60)
		init->error = 0;
	if (init->error == 0)
	{
		write(2, "Map Error  \n", 10);
		ft_free(init->size_map_vertical, init->str);
		return (0);
	}
	ft_free(init->size_map_vertical, init->str);
	init->fd = open(av[1], O_RDONLY);
	ft_read_file_to_array(init->fd, init);
	return (1);
}
