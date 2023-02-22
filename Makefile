# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/02/15 11:21:33 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./libs/minilibx -lm -lmlx -Ilmlx -lXext -lX11
DEPS = libs/minilibx/mlx.h libs/libft/libft.a

NAME = so_long
SRC = main.c map_check.c map_check_utils.c
OBJ = $(SRC:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx
	
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -g -o $(NAME)

clean:
	$(MAKE) $@ -C ./libs/libft
	$(MAKE) $@ -C ./libs/minilibx
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libs/libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libs/libft
	$(MAKE) re -C ./libs/minilibx
