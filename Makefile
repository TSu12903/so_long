# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2025/01/08 12:19:14 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	:= ./mandatory
OBJDIR := ./obj
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
NAME := so_long
LIBFT := libft/libft.a
LIB := libft
SRC :=	parsing \

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo ✔ Good

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIB) clean
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY : all clean fclean re
