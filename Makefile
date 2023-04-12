# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/04/12 15:58:34 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11 
DEPS = libs/minilibx-linux/mlx.h libs/libft/libft.a

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = src/main.c src/map_check.c src/map_check_utils.c src/render_map.c src/move_player.c src/free.c src/init.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = src_bonus/main.c src_bonus/map_check.c src_bonus/map_check_utils.c src_bonus/render.c src_bonus/render_map.c \
			src_bonus/move_player.c src_bonus/idle_animation.c src_bonus/extra_animations.c src_bonus/move_enemy.c \
			src_bonus/init.c src_bonus/free.c src_bonus/walk_animation.c src_bonus/enemy_animations.c src_bonus/player_animations.c \
			src_bonus/init_enemy.c src_bonus/utils.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx-linux
	
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)	

clean:
	$(MAKE) $@ -C ./libs/libft
	$(MAKE) $@ -C ./libs/minilibx-linux
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)

fclean: clean
	$(MAKE) $@ -C ./libs/libft
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re: fclean all
	$(MAKE) re -C ./libs/libft
	$(MAKE) re -C ./libs/minilibx-linux

reb: fclean bonus
	$(MAKE) re -C ./libs/libft
	$(MAKE) re -C ./libs/minilibx-linux
