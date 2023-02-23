/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/23 12:49:19 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*---------- LIBRARIES ----------*/

#include "libs/minilibx/mlx.h"
#include "libs/libft/libft.h"

#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include <fcntl.h>

/*---------- STRUCTURES ----------*/

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_map
{
	char	**layout;
	int		lines;
	int		len;
	int		collect;
	int		gathered;
	t_point	start;
	t_point	exit;
}	t_map;

/*---------- VARIABLES ----------*/

#define W_WIDTH 1200
#define W_HEIGHT 600

/*---------- FUNCTIONS ----------*/

int	map_check(char *file);
int	dimension_check(t_map *map);
int	wall_check(t_map *map);
int	comp_check(t_map *map);
int	comp_check_check(t_map *map, int x, int y);
int	comp_check_check_check(t_map *map, int start_exit);
int	path_check(char *file, t_map *map);
void	fill(char **layout_cpy, t_map *map, int x, int y);
char	**file_to_map(char *file);
int		strlen_so_long(char *str);

#endif
