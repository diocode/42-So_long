# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/02/08 13:29:32 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./src/minilibx -lm -lmlx -Ilmlx -lXext -lX11
DEPS = src/minilibx/mlx.h src/libft/libft.a

NAME = so_long
SRC = main.c
OBJ = $(SRC:.c=.o)

LIBFT = src/libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./src/libft
	$(MAKE) -C ./src/minilibx
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) $@ -C ./src/libft
	$(MAKE) $@ -C ./src/minilibx
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./src/libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./src/libft
	$(MAKE) re -C ./src/minilibx
