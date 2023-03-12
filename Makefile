# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/03/09 19:32:32 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -L ./libs/minilibx -lm -lmlx -Ilmlx -lXext -lX11
DEPS = libs/minilibx/mlx.h libs/libft/libft.a

NAME = so_long
NAME_BONUS = so_long_bonus


SRC = src/so_long.c src/map_check.c src/map_check_utils.c src/render.c src/render_utils.c src/move_player.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = src_bonus/so_long_bonus.c src_bonus/map_check_bonus.c src_bonus/map_check_utils_bonus.c src_bonus/render_bonus.c src_bonus/render_utils_bonus.c src_bonus/move_player_bonus.c src_bonus/animate_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx
	
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)	

clean:
	$(MAKE) $@ -C ./libs/libft
	$(MAKE) $@ -C ./libs/minilibx
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)

fclean: clean
	$(MAKE) $@ -C ./libs/libft
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re: fclean all
	$(MAKE) re -C ./libs/libft
	$(MAKE) re -C ./libs/minilibx

reb: fclean bonus
	$(MAKE) re -C ./libs/libft
	$(MAKE) re -C ./libs/minilibx
