/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:18 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/29 15:59:23 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void move_enemy(t_data *data, int enemies)
{
	int	n;
	
	n = (rand() % 4) + 1;
	if (n == 1)
	{
		if (data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == '1'
				|| data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == 'E'
				|| data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == 'X')
			return ;
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = '0';
		enemy_up(data, enemies);
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = 'X';
	}
	if (n == 2)
	{
		if (data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == '1'
				|| data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == 'E'
				|| data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == 'X')
			return ;
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = '0';
		enemy_down(data, enemies);
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = 'X';
	}
	if (n == 3)
	{
		if (data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == '1'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == 'E'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == 'X')
			return ;
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = '0';
		enemy_right(data, enemies);
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = 'X';
	}
	if (n == 4)
	{
		if (data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == '1'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == 'E'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == 'X')
			return ;
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = '0';
		enemy_left(data, enemies);
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = 'X';
	}	
}

void	render_enemies(t_data *data)
{
	int enemies;
	enemies = -1;
	while (++enemies < data->map->enemies)
	{
		put_tile(data, "./textures/enemy_1.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
		data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies]] = 'X';
	}
}

void enemy_up(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_y[enemies];
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	data->map->enemy_y[enemies] -= 1;
	put_tile(data, "./textures/enemy_1.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE + (SIZE / 2));
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	usleep(15000);
	put_tile(data, "./textures/enemy_2.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	usleep(15000);
}

void enemy_down(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_y[enemies];
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	data->map->enemy_y[enemies] += 1;
	put_tile(data, "./textures/enemy_1.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE - (SIZE / 2));
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	usleep(15000);
	put_tile(data, "./textures/enemy_2.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	usleep(15000);
}

void enemy_right(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_x[enemies];
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	data->map->enemy_x[enemies] += 1;
	put_tile(data, "./textures/enemy_1.xpm", data->map->enemy_x[enemies] * SIZE - (SIZE / 2), data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	usleep(15000);
	put_tile(data, "./textures/enemy_2.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	usleep(15000);
}

void enemy_left(t_data *data, int enemies)
{
	int	floor;

	floor = data->map->enemy_x[enemies];
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	data->map->enemy_x[enemies] -= 1;
	put_tile(data, "./textures/r_enemy_1.xpm", data->map->enemy_x[enemies] * SIZE + (SIZE / 2), data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	usleep(15000);
	put_tile(data, "./textures/r_enemy_2.xpm", data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	usleep(15000);
}

void	kill_player(t_data *data)
{
	//(void)
}