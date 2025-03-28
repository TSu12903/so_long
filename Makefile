CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(MLXDIR) -Ilibft
NAME = so_long

LIBFT = Library/libft/libft.a
LIB = Library/libft
MLXDIR = Library/minilibx-linux
MLX = $(MLXDIR)/libmlx_Linux.a
LIBMLX = -L$(MLXDIR) -lmlx_Linux -lXext -lX11 -lm -lz

SRC = Mandatory/parsing/parsing1.c \
	  Mandatory/parsing/parsing_check.c \
	  Mandatory/parsing/parsing_item.c \
	  Mandatory/windows/get_window.c \
	  Mandatory/windows/mlx_destroy.c \
	  Mandatory/windows/mlx_Map.c \
	  Mandatory/utils/utils_parsing.c \
	  Mandatory/init/init.c \
	  Mandatory/main.c

SRC_BONUS = bonus/parsing/parsing1_bonus.c \
            bonus/parsing/parsing_check_bonus.c \
            bonus/parsing/parsing_item_bonus.c \
            bonus/windows/get_window_bonus.c \
            bonus/windows/mlx_destroy_bonus.c \
            bonus/windows/mlx_Map_bonus.c \
            bonus/utils/utils_parsing_bonus.c \
            bonus/init_bonus/init_bonus.c \
            bonus/main_bonus.c

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJDIR)/,$(SRC_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo "✔ GOOD $(NAME)"

bonus: $(OBJ_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo "✔ GOOD $(NAME)"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

$(MLX):
	@$(MAKE) -C $(MLXDIR) -s

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIB) clean
	@$(MAKE) -C $(MLXDIR) clean
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIB) fclean
	@echo "Full clean done"

re: fclean all

.PHONY: all bonus clean fclean re
