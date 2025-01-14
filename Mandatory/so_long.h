/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/14 12:54:28 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

typedef struct s_init
{
    int i;
    int j;
    int parsing;

}       t_init;

////////////////////////////////////////
///				parsing.c			///
//////////////////////////////////////

int parsing(char **av, t_init *init);

////////////////////////////////////////
///				utils_parsing.c		///
//////////////////////////////////////

int ft_free_structure(t_init *init);

#endif