/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/27 23:00:30 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---------- LIBRARIES ---------- */

# include <stdlib.h>
# include "libft.h"
# include "../libs/minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

/*---------- VARIABLES ----------*/

# define SIZE 64
# define NUM_TILES 13

/* ---------- STRUCS ---------- */

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_map
{
	char	**layout;
	int	valid;
	int	lines;
	int	len;
	int	collect;
	int	gathered;
	t_point	player;
	t_point	exit;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**tiles;
	t_map	*map;
	t_img	img;
	t_point	tile;
	int		moves;
}	t_data;

/*---------- FUNCTIONS ----------*/

t_data	*init_data(void);
t_data	*init(void);
void	init_null(t_data *data);
void	init_img1(t_data *data);
void	init_img2(t_data *data);

void	render_wall_corner(t_data *data, int y, int x);
void	render_wall_border(t_data *data, int y, int x);
void	render_tile(t_data *data, int y, int x);
int		render_win(t_data *data);
int		render_map(t_data *data);
int		render(t_data *data);

void	map_check(char *file, t_data *data);
int		path_check(char *file, t_data *data);
int		wall_check(t_data *data);
int		dimension_check(t_data *data);
int		comp1_check(t_data *data);
int		comp2_check(t_data *data, int x, int y);
int		comp3_check(t_data *data, int start_exit);

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

char	**file_to_map(char *file);
void	fill(char **layout_cpy, t_data *data, int x, int y);
int		map_lines(char *file);
int		strlen_solong(char *str);
int		handle_keypress(int keysym, t_data *data);

void	free_map(t_map *map);
void	free_tiles(t_data *data);
int		ft_quit(t_data *data);
int		free_game(t_data *data);

#endif
