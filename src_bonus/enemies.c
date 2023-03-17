/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:18 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/17 18:27:40 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	generate_enemies(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map.layout[++y])
	{
		x = -1;
		while (data->map.layout[y][++x])
			if (data->map.layout[y][x] == 'X')
				data->map.enemies++;
	}

	data->map.enemy_x = (int *) malloc(sizeof(int) * data->map.enemies);
	data->map.enemy_y = (int *) malloc(sizeof(int) * data->map.enemies);
	data->map.enemies = 0;
}

int move_enemy(t_data *data)
{
	int	n;
	int	floor;
	int	t;

	n = (rand() % (4 - 1 + 1)) + 1;
	floor = data->map.enemy_x[data->map.enemies];
	if (n == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.enemy_y[data->map.enemies] * TILE);
		data->map.enemy_y[data->map.enemies] -= 1;
		t = 0;
		while(t < 18000)
		{	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.enemy_1, data->map.enemy_x[data->map.enemies] * TILE, data->map.enemy_y[data->map.enemies] * TILE - (TILE / 6));
			t++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.enemy_y[data->map.enemies] * TILE);
		t = 0;
		while(t < 18000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.enemy_1, data->map.enemy_x[data->map.enemies] * TILE, data->map.enemy_y[data->map.enemies] * TILE - (TILE / 3));
			t++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.enemy_y[data->map.enemies] * TILE);
		t = 0;
		while(t < 18000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.enemy_1, data->map.enemy_x[data->map.enemies] * TILE, data->map.enemy_y[data->map.enemies] * TILE);
			t++;
		}
		return (0);		
	}
	return (0);	
}