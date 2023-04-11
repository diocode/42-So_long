/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:04 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/10 16:27:21 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	render_wall_corner(t_data *data, int y, int x)
{
	if (y == 0 && x == 0)
		put_tile(data, "./textures/wall_u_l.xpm", x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x == 0)
		put_tile(data, "./textures/wall_d_l.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x == data->map->len - 1)
		put_tile(data, "./textures/wall_u_r.xpm", x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x == data->map->len - 1)
		put_tile(data, "./textures/wall_d_r.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x > 0 && x < data->map->len - 1)
		put_tile(data, "./textures/wall_m.xpm", x * SIZE, y * SIZE);
}

static void	render_wall_border(t_data *data, int y, int x)
{
	if (y == 0 && x > 0 && x < data->map->len - 1)
		put_tile(data, "./textures/wall_u.xpm", x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x > 0 && x < data->map->len - 1)
		put_tile(data, "./textures/wall_d.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x == 0)
		put_tile(data, "./textures/wall_l.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x == data->map->len - 1)
		put_tile(data, "./textures/wall_r.xpm", x * SIZE, y * SIZE);
}

static void	render_tiles(t_data *data, int y, int x)
{
	if (data->map->layout[y][x] == '0')
		put_tile(data, "./textures/floor.xpm", x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'C')
		put_tile(data, "./textures/collect_idle_1.xpm", x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'P')
		put_tile(data, "./textures/player_idle_1.xpm", x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'E')
		put_tile(data, "./textures/exit_1.xpm", x * SIZE, y * SIZE);
}

static void	render_moves(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->map->len % 2 != 0)
			put_tile(data, data->nbr[0],
				(data->map->len / 2 * SIZE + 96) - i * 32,
				data->map->lines * SIZE);
		else
			put_tile(data, data->nbr[0],
				(data->map->len / 2 * SIZE + 64) - i * 32,
				data->map->lines * SIZE);
		i++;
	}
}

int	render_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map->layout[++y])
	{
		x = -1;
		while (data->map->layout[y][++x])
		{
			if (data->map->layout[y][x] == '1')
			{
				render_wall_corner(data, y, x);
				render_wall_border(data, y, x);
			}
			else
				render_tiles(data, y, x);
		}
	}
	render_moves(data);
	return (0);
}
