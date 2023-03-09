# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/03/09 15:57:09 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -L ./libs/minilibx -lm -lmlx -Ilmlx -lXext -lX11
DEPS = libs/minilibx/mlx.h libs/libft/libft.a

NAME = so_long

SRC = src/so_long.c src/map_check.c src/map_check_utils.c src/render.c src/render_utils.c src/move_player.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = src/so_long_bonus.c src/map_check_bonus.c src/map_check_utils_bonus.c src/render_bonus.c src/render_utils_bonus.c src/move_player_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx
	
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -g -o $(NAME)

bonus: deps $(NAME)

$(NAME): $(OBJ_BONUS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -g -o $(NAME)	

clean:
	$(MAKE) $@ -C ./libs/libft
	$(MAKE) $@ -C ./libs/minilibx
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)

fclean: clean
	$(MAKE) $@ -C ./libs/libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libs/libft
	$(MAKE) re -C ./libs/minilibx
