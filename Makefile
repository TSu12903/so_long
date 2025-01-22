# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2025/01/22 15:26:42 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR  := ./Mandatory
OBJDIR  := ./obj
CC      := cc
CFLAGS  := -Wall -Werror -Wextra -g -I$(MLXDIR) -Ilibft
NAME    := so_long
LIBFT   := Library/libft/libft.a
LIB     := Library/libft
SRC     := parsing/parsing1.c \
           parsing/parsing_check.c \
           parsing/parsing_item.c \
           windows/get_window.c \
		   windows/mlx_destroy.c \
		   windows/picture_map.c \
           utils/utils_parsing.c \
           init/init.c \
           main.c \

MLXDIR  := Library/minilibx-linux
MLX     := $(MLXDIR)/libmlx_Linux.a
OBJ     := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
LIBMLX  := -L$(MLXDIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo ✔ GOOD

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

$(MLX):
	@$(MAKE) -C $(MLXDIR) -s

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIB) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB) fclean
	@$(MAKE) -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re
