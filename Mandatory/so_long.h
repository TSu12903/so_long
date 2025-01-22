/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:01:41 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/22 17:00:39 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Library/libft/libft.h"
#include <fcntl.h>
#include "../Library/minilibx-linux/mlx.h"

typedef struct s_point
{
	int y;
	int x;

}		t_point;

typedef struct s_init
{
	int i;
	int j;
	int k;
	int	pixel_hor;
	int	pixel_ver;
	int	fd;
	int exit;
	int item;
	int start;
	int verif;
	int parsing;
	int size_map_vertical;
	int size_map_horizontal;
	int error;
	char	**str;

	void	*mlx;
	void	*mlx_win;
	int		img_width;
	int		img_height;
	void	*img_wall_top;
	void	*img_wall_ground;
	void	*img_wall_key;
	void	*img_wall_prisoner;
	void	*img_wall_door;

}       t_init;

////////////////////////////////////////
///				init.c				///
//////////////////////////////////////

void    ft_init(t_init *init);

////////////////////////////////////////
///				parsing1.c			///
//////////////////////////////////////

int parsing(char **av, t_init *init, t_point *start);

////////////////////////////////////////
///				parsing_check.c		///
//////////////////////////////////////

void	ft_check(t_init *init, t_point *start);

////////////////////////////////////////
///				parsing_item.c		///
//////////////////////////////////////

void    ft_check_items_acces(t_init *init, t_point *start);

////////////////////////////////////////
///				utils_parsing.c		///
//////////////////////////////////////

int     ft_free_structure(t_init *init);
int		ft_free_structure_windows(t_init *init);
void    ft_free(int i, char **str);
int	    ft_strlen_map_v(t_init *init);
int	    ft_strlen_map_h(int j, t_init *init);

////////////////////////////////////////
///				get_window.c		///
//////////////////////////////////////

void	start_window(t_init *init);
int		ft_close(t_init *init);

////////////////////////////////////////
///				mlx_destroy.c		///
//////////////////////////////////////

void    ft_destroy(t_init *init);

////////////////////////////////////////
///				mlx_destroy.c		///
//////////////////////////////////////

void	ft_draw_wall(t_init *init);
void	ft_draw_key(t_init *init);
void	ft_draw_prisoner(t_init *init);

#endif
