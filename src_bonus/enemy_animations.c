/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:20:32 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 13:06:06 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void enemy_up(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_y[enemies];
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE,
			floor * SIZE);
	data->map->enemy_y[enemies] -= 1;
	put_tile(data, "./textures/enemy_1.xpm", data->map->enemy_x[enemies] * SIZE,
			data->map->enemy_y[enemies] * SIZE + (SIZE / 2));
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE,
			floor * SIZE);
	usleep(50000);
	put_tile(data, "./textures/enemy_3.xpm", data->map->enemy_x[enemies] * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE,
			floor * SIZE);
}

void enemy_down(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_y[enemies];
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE,
			floor * SIZE);
	data->map->enemy_y[enemies] += 1;
	put_tile(data, "./textures/enemy_2.xpm", data->map->enemy_x[enemies] * SIZE,
			data->map->enemy_y[enemies] * SIZE - (SIZE / 2));
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE,
			floor * SIZE);
	usleep(50000);
	put_tile(data, "./textures/enemy_3.xpm", data->map->enemy_x[enemies] * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE,
			floor * SIZE);
}

void enemy_right(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_x[enemies];
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	data->map->enemy_x[enemies] += 1;
	put_tile(data, "./textures/enemy_2.xpm",
			data->map->enemy_x[enemies] * SIZE - (SIZE / 2),
			data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	usleep(50000);
	put_tile(data, "./textures/enemy_1.xpm",
			data->map->enemy_x[enemies] * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->enemy_y[enemies] * SIZE);
}

void enemy_left(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_x[enemies];
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	data->map->enemy_x[enemies] -= 1;
	put_tile(data, "./textures/r_enemy_3.xpm",
			data->map->enemy_x[enemies] * SIZE + (SIZE / 2),
			data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	usleep(50000);
	put_tile(data, "./textures/r_enemy_2.xpm",
			data->map->enemy_x[enemies] * SIZE,
			data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE,
			data->map->enemy_y[enemies] * SIZE);
}
