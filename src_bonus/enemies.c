/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:18 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 10:28:23 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	generate_enemies(t_data *data)
{
	int	x;
	int	y;
	int	enemies;

	y = -1;
	while (data->map.layout[++y])
	{
		x = -1;
		while (data->map.layout[y][++x])
			if (data->map.layout[y][x] == '0')
				data->map.zero++;
	}

	data->map.enemies = data->map.zero / 20;
	if (data->map.enemies == 0)
		data->map.enemies = 1;
	data->map.enemy_x = ft_calloc(data->map.enemies, sizeof(int));
	data->map.enemy_y = ft_calloc(data->map.enemies, sizeof(int));
	if (!data->map.enemy_x || !data->map.enemy_y)
		free_data(data);
	enemies = data->map.enemies;
	while (enemies >= 0)
	{
		x = 0;
		y = 0;
		while (data->map.layout[y][x] != '0')
		{
			x = rand() % (data->map.len - 1);
			y = rand() % (data->map.lines - 1);
		}
		data->map.enemy_x[enemies] = x;
		data->map.enemy_y[enemies] = y;
		enemies--;
	}
}

void move_enemy(t_data *data, int enemies)
{
	int	n;
	
	return ;
	n = (rand() % 4) + 1;
	if (n == 1)
	{
		if (data->map.layout[data->map.enemy_y[enemies] - 1][data->map.enemy_x[enemies]] == '1'
				|| data->map.layout[data->map.enemy_y[enemies] - 1][data->map.enemy_x[enemies]] == 'C'
				|| data->map.layout[data->map.enemy_y[enemies] - 1][data->map.enemy_x[enemies]] == 'E')
			return ;
		enemy_up(data, enemies);
	}
	if (n == 2)
	{
		if (data->map.layout[data->map.enemy_y[enemies] + 1][data->map.enemy_x[enemies]] == '1'
				|| data->map.layout[data->map.enemy_y[enemies] + 1][data->map.enemy_x[enemies]] == 'C'
				|| data->map.layout[data->map.enemy_y[enemies] + 1][data->map.enemy_x[enemies]] == 'E')
			return ;
		enemy_down(data, enemies);
	}
	if (n == 3)
	{
		if (data->map.layout[data->map.enemy_y[enemies]][data->map.enemy_x[enemies] + 1] == '1'
				|| data->map.layout[data->map.enemy_y[enemies]][data->map.enemy_x[enemies] + 1] == 'C'
				|| data->map.layout[data->map.enemy_y[enemies]][data->map.enemy_x[enemies] + 1] == 'E')
			return ;
		enemy_right(data, enemies);
	}
	if (n == 4)
	{
		if (data->map.layout[data->map.enemy_y[enemies]][data->map.enemy_x[enemies] - 1] == '1'
				|| data->map.layout[data->map.enemy_y[enemies]][data->map.enemy_x[enemies] - 1] == 'C'
				|| data->map.layout[data->map.enemy_y[enemies]][data->map.enemy_x[enemies] - 1] == 'E')
			return ;
		enemy_left(data, enemies);
	}	
}

void	render_enemies(t_data *data)
{
	int enemies;
	enemies = -1;
	while (++enemies < data->map.enemies)
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
                data->map.tiles.enemy_3, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE);
}

void enemy_up(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map.enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, data->map.enemy_x[enemies] * TILE, floor * TILE);
	data->map.enemy_y[enemies] -= 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE + (TILE / 3));
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, data->map.enemy_x[enemies] * TILE, floor * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_2, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE + (TILE / 6));
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, data->map.enemy_x[enemies] * TILE, floor * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_3, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE);
		t++;
	}
}

void enemy_down(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map.enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, data->map.enemy_x[enemies] * TILE, floor * TILE);
	data->map.enemy_y[enemies] += 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE - (TILE / 3));
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, data->map.enemy_x[enemies] * TILE, floor * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_2, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE - (TILE / 6));
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, data->map.enemy_x[enemies] * TILE, floor * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_3, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies] * TILE);
		t++;
	}
}

void enemy_right(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map.enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, floor * TILE, data->map.enemy_y[enemies] * TILE);
	data->map.enemy_x[enemies] += 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE - (TILE / 3) * TILE, data->map.enemy_y[enemies]);
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, floor * TILE, data->map.enemy_y[enemies] * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE - (TILE / 6) * TILE, data->map.enemy_y[enemies]);
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, floor * TILE, data->map.enemy_y[enemies] * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies]);
	}
}

void enemy_left(t_data *data, int enemies)
{
	int	floor;
	int	t;

	floor = data->map.enemy_y[enemies];
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, floor * TILE, data->map.enemy_y[enemies] * TILE);
	data->map.enemy_x[enemies] -= 1;
	t = 0;
	while(t < 20000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE + (TILE / 3) * TILE, data->map.enemy_y[enemies]);
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, floor * TILE, data->map.enemy_y[enemies] * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE + (TILE / 6) * TILE, data->map.enemy_y[enemies]);
		t++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map.tiles.floor, floor * TILE, data->map.enemy_y[enemies] * TILE);
	t = 0;
	while(t < 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.enemy_1, data->map.enemy_x[enemies] * TILE, data->map.enemy_y[enemies]);
	}
}