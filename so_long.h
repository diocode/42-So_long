/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/03 13:00:29 by digoncal         ###   ########.fr       */
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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
	t_point	size;
	t_point	tile;
	
}	t_data;

/*---------- VARIABLES ----------*/

#define TILE 50

/*---------- FUNCTIONS ----------*/

void	map_check(char *file, t_data *data);
int	render(t_data *data);
int	dimension_check(t_data *data);
int	wall_check(t_data *data);
int	comp_check(t_data *data);
int	comp_check_check(t_data *data, int x, int y);
int	comp_check_check_check(t_data *data, int start_exit);
int	path_check(char *file, t_data *data);
void	fill(char **layout_cpy, t_data *data, int x, int y);
char	**file_to_map(char *file);
int	strlen_solong(char *str);
int	render_win(t_data *data);
int	render_map(t_data *data);
t_data	*generate_data(void);
void	render_wall_border(t_data *data, int x, int y);
void	render_wall_corner(t_data *data, int x, int y);
void	render_tile(t_data *data, int x, int y);
void	move_player(t_data *data);

#endif
