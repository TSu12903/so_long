/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:26 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/14 16:30:27 by tcybak           ###   ########.fr       */
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
	return (ft_strncmp(&av[len-4], ".ber", len));
}

int	parsing(char **av, t_init *init)
{
	int		fd;
	char	*str;

	init->verif = verif_arg_ber(av[1] , *init);
	if (init->verif != 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != 0)
	{
		ft_printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}