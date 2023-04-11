/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/11 14:43:50 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---------- LIBRARIES ---------- */

# include <stdlib.h>
# include "libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <time.h>

/*---------- VARIABLES ----------*/

# define SIZE 64

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

typedef struct s_map
{
	char	**layout;
	int	valid;
	int	lines;
	int	len;
	int	collect;
	int	gathered;
	int	enemies;
	int	*enemy_x;
	int	*enemy_y;
	t_point	player;
	t_point	exit;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**nbr;
	int		moves;
	int		loop;
	int		idle;
	int		finish;
	int		direc;
	int		atk;
	t_map	*map;
	t_img	img;
	t_point	tile;
}	t_data;

/*---------- FUNCTIONS ----------*/

t_data	*init(void);
t_data	*init_data(void);
void	init_null(t_data *data);
void	init_img(t_data *data);
int		init_nbr(t_data *data);
int		init_enemy(t_data *data);

void	render_enemies(t_data *data);
int		render_win(t_data *data);
int		render_map(t_data *data);
int		render(t_data *data);

void	map_check(char *file, t_data *data);
int		map_lines(char *file);
int		path_check(char *file, t_data *data);
int		dimension_check(t_data *data);
int		wall_check(t_data *data);
int		comp1_check(t_data *data);
int		comp2_check(t_data *data, int x, int y);
int		comp3_check(t_data *data, int start_exit);

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

void	move_enemy(t_data *data, int enemies);
void	enemy_up(t_data *data, int enemies);
void	enemy_down(t_data *data, int enemies);
void	enemy_right(t_data *data, int enemies);
void	enemy_left(t_data *data, int enemies);

void	walk_right(t_data *data);
void	walk_left(t_data *data);
void	walk_up(t_data *data);
void	walk_down(t_data *data);
int		player_idle(t_data *data);

void	start_anim(t_data *data);
void	exit_anim(t_data *data);
void	atk1(t_data *data);
void	kill_player(t_data *data);
void	nbr_moves_animation(t_data	*data);

void	free_tiles(t_data *data);
void	free_map(t_map *map);
void	free_array(char **arr, int lines);
int		ft_quit(t_data *data);
int		free_game(t_data *data);

void    put_tile(t_data *data, char *tile, int x, int y);
void	fill(char **layout_cpy, t_data *data, int x, int y);
void	enemy_pos(t_data *data, int moves);
char	**file_to_map(char *file);
int		handle_keypress(int keysym, t_data *data);
int		strlen_solong(char *str);
int		file_check(char *str);

#endif
