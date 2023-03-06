/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/06 21:21:14 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---------- LIBRARIES ---------- */

# include <stdlib.h>
# include "libs/libft//libft.h"
# include "libs/minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

/* ---------- STRUCS ---------- */

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_tiles
{
	void	*collect;
	void	*exit;
	void	*floor;
	void	*player;
	void	*wall_d_l;
	void	*wall_d_r;
	void	*wall_d;
	void	*wall_l;
	void	*wall_m;
	void	*wall_r;
	void	*wall_u_l;
	void	*wall_u_r;
	void	*wall_u;
}	t_tiles;

typedef struct s_map
{
	char	**layout;
	int	valid;
	int	lines;
	int	len;
	int	collect;
	int	gathered;
	t_tiles	tiles;
	t_point	player;
	t_point	exit;
}	t_map;



typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
	t_point	tile;
	int		moves;
}	t_data;

/*---------- VARIABLES ----------*/

#define TILE 50

/*---------- FUNCTIONS ----------*/

int	render_win(t_data *data);
int	render_map(t_data *data);
int	render(t_data *data);
int	dimension_check(t_data *data);
int	wall_check(t_data *data);
int	comp_check(t_data *data);
int	comp_check_check(t_data *data, int x, int y);
int	comp_check_check_check(t_data *data, int start_exit);
int	path_check(char *file, t_data *data);
int	strlen_solong(char *str);
void	generate_img(t_data *data);
void	fill(char **layout_cpy, t_data *data, int x, int y);
void	render_wall_corner(t_data *data, int y, int x);
void	render_wall_border(t_data *data, int y, int x);
void	render_tile(t_data *data, int y, int x);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	map_check(char *file, t_data *data);
char	**file_to_map(char *file);
t_data	*generate_data(void);

#endif
