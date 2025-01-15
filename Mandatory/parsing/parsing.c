/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:26 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/15 11:15:05 by tcybak           ###   ########.fr       */
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

int	parsing(char **av, t_init *init)
{
	int		fd;
	char	*final;
	char	*gnl_result;
	char 	*tmp;
	char	**str;

	init->verif = verif_arg_ber(av[1] , *init);
	if (init->verif != 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	final = ft_calloc(1, 1);
	if (final == 0)
		return (0);
	gnl_result = get_next_line(fd);
	while (gnl_result != 0)
	{
		tmp = ft_strjoin(final, gnl_result);
		free(final);
		free(gnl_result);
		final = tmp; // tmp et str1 meme adresse
		gnl_result = get_next_line(fd);
		ft_printf("%s\n", final);
	}
	str = ft_split(final, '\n');
	free(final);
	int	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
	ft_free(i, str);
	close(fd);
	return (0);
}
