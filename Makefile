# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2025/01/17 16:43:01 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR  := ./Mandatory
OBJDIR  := ./obj
CC      := cc
CFLAGS  := -Wall -Werror -Wextra -g -I$(MLXDIR) -Ilibft
NAME    := so_long
LIBFT   := libft/libft.a
LIB     := libft
SRC     := parsing/parsing1.c \
           parsing/parsing_check.c \
           parsing/parsing_item.c \
           utils/utils_parsing.c \
           init/init.c \
           main.c \

MLXDIR  := minilibx-linux
MLX     := $(MLXDIR)/libmlx_Linux.a
OBJ     := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
LIBMLX  := -L$(MLXDIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo ✔ Compilation réussie

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
