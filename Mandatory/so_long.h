/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/16 11:35:41 by tcybak           ###   ########.fr       */
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
    int k;
    int exit;
    int item;
    int start;
    int verif;
    int parsing;
    int size_map_vertical;
    int size_map_horizontal;
    int error;

}       t_init;

////////////////////////////////////////
///				init.c			///
//////////////////////////////////////

void    ft_init(t_init *init);

////////////////////////////////////////
///				parsing1.c			///
//////////////////////////////////////

int parsing(char **av, t_init *init, t_tab *tab);

////////////////////////////////////////
///				parsing2.c			///
//////////////////////////////////////

void	ft_check(t_init *init, t_tab *tab);

////////////////////////////////////////
///				utils_parsing.c		///
//////////////////////////////////////

int     ft_free_structure(t_init *init, t_tab *tab);
void    ft_free(int i, char **str);
int     ft_free_init(t_init *init);
int	    ft_strlen_map_v(t_tab *tab);
int	    ft_strlen_map_h(int j, t_tab *tab);

#endif