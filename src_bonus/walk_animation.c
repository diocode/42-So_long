/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:20:18 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 15:34:29 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	walk_right(t_data *data)
{
	int	floor;

	floor = data->map->player.x;
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->player.y * SIZE);
	data->map->player.x += 1;
	put_tile(data, "./textures/player_walk_1.xpm",
			data->map->player.x * SIZE - (SIZE / 2),data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->player.y * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_walk_2.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->player.y * SIZE);
	usleep(100000);
}

void	walk_left(t_data *data)
{
	int	floor;

	floor = data->map->player.x;
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->player.y * SIZE);
	data->map->player.x -= 1;
	put_tile(data, "./textures/r_player_walk_1.xpm",
			data->map->player.x * SIZE + (SIZE / 2),
			data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->player.y * SIZE);
	usleep(150000);
	put_tile(data, "./textures/r_player_walk_2.xpm",
			data->map->player.x * SIZE, data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->player.y * SIZE);
	usleep(100000);
}

void	walk_up(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	data->map->player.y -= 1;
	put_tile(data, "./textures/player_up_1.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE + ((SIZE / 3) * 2));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_up_2.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE + (SIZE / 3));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_up_3.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	usleep(100000);
}

void	walk_down(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	data->map->player.y += 1;
	put_tile(data, "./textures/player_down_1.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE - ((SIZE / 3) * 2));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_down_2.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE - (SIZE / 3));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_down_3.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE,
			floor * SIZE);
	usleep(100000);
}
