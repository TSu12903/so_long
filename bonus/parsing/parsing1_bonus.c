/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:26 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/31 13:04:40 by tcybak           ###   ########.fr       */
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

void	ft_read_line_follow(t_init *init)
{
	if (*init->str == NULL)
	{
		free(init->str);
		close(init->fd);
		ft_free_structure(init);
		write(2, "Error\nEmpty map\n", 16);
		exit (1);
	}
	init->size_map_vertical = ft_strlen_map_v(init);
	init->size_map_horizontal = ft_strlen_map_h(init->k, init);
}

void	ft_read_file_to_array(int fd, t_init *init)
{
	char	*final;
	char	*gnl_result;
	char	*tmp;

	if (fd == -1)
		return ;
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
	free(final);
	ft_read_line_follow(init);
	close(init->fd);
}

void	ft_verif_empty_map(char **av, t_init *init)
{
	char	*gnl_result;

	init->fd = open(av[1], O_RDONLY);
	if (init->fd == -1)
	{
		init->error = 0;
		return ;
	}
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
		write(2, "Error\nFile\n", 11);
		return (0);
	}
	init->fd = open(av[1], O_RDONLY);
	ft_read_file_to_array(init->fd, init);
	ft_check(init, start);
	ft_check_items_acces(init, start);
	if (init->size_map_vertical + 1 > 60 || init->size_map_horizontal + 1 > 60)
		init->error = 0;
	if (init->error == 0)
	{
		write(2, "Error\nMap\n", 10);
		ft_free(init->size_map_vertical, init->str);
		return (0);
	}
	ft_free(init->size_map_vertical, init->str);
	init->fd = open(av[1], O_RDONLY);
	ft_read_file_to_array(init->fd, init);
	return (1);
}
