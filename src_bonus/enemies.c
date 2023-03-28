/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:18 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/28 22:23:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void move_enemy(t_data *data, int enemies)
{
	int	n;
	
	return ;
	n = (rand() % 4) + 1;
	if (n == 1)
	{
		if (data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == '1'
				|| data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies] - 1][data->map->enemy_x[enemies]] == 'E')
			return ;
		enemy_up(data, enemies);
	}
	if (n == 2)
	{
		if (data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == '1'
				|| data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies] + 1][data->map->enemy_x[enemies]] == 'E')
			return ;
		enemy_down(data, enemies);
	}
	if (n == 3)
	{
		if (data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == '1'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] + 1] == 'E')
			return ;
		enemy_right(data, enemies);
	}
	if (n == 4)
	{
		if (data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == '1'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == 'C'
				|| data->map->layout[data->map->enemy_y[enemies]][data->map->enemy_x[enemies] - 1] == 'E')
			return ;
		enemy_left(data, enemies);
	}	
}

void	render_enemies(t_data *data)
{
	int enemies;
	enemies = -1;
	while (++enemies < data->map->enemies)
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
                data->tiles[39], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
}

void enemy_up(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map->enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	data->map->enemy_y[enemies] -= 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[38], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE + (SIZE / 5));
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[39], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
		t++;
	}
}

void enemy_down(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map->enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	data->map->enemy_y[enemies] += 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[38], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE - (SIZE / 5));
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->enemy_x[enemies] * SIZE, floor * SIZE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[39], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies] * SIZE);
		t++;
	}
}

void enemy_right(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map->enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	data->map->enemy_x[enemies] += 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[38], data->map->enemy_x[enemies] * SIZE - (SIZE / 5) * SIZE, data->map->enemy_y[enemies]);
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[39], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies]);
		t++;
	}
}

void enemy_left(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map->enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	data->map->enemy_x[enemies] -= 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[38], data->map->enemy_x[enemies] * SIZE + (SIZE / 5) * SIZE, data->map->enemy_y[enemies]);
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->enemy_y[enemies] * SIZE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[39], data->map->enemy_x[enemies] * SIZE, data->map->enemy_y[enemies]);
		t++;
	}
}