/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/15 13:19:46 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
#include <fcntl.h>

typedef struct s_tab
{
    char	**str;

}           t_tab;

typedef struct s_init
{
    int i;
    int j;
    int verif;
    int parsing;

}       t_init;

////////////////////////////////////////
///				parsing.c			///
//////////////////////////////////////

int parsing(char **av, t_init *init, t_tab *tab);

////////////////////////////////////////
///				utils_parsing.c		///
//////////////////////////////////////

int     ft_free_structure(t_init *init, t_tab *tab);
void    ft_free(int i, char **str);
int     ft_free_init(t_init *init);

#endif