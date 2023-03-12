/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:18:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/12 12:55:36 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_idle(t_data *data)
{
	int	x;
	int	y;

	x = data->map.player.x;
	y = data->map.player.y;
	if (data->loop < 12000)
	{
		data->loop++;
		return (0);
	}
	data->loop = 0;
	if (data->direc == 'r')
	{
		if (!data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.player_idle_2, x * TILE, y * TILE);
			data->idle = 1;
			return (0);
		}
		if (data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.player_idle_1, x * TILE, y * TILE);
			data->idle = 0;
			return (0);
		}
	}
	if (data->direc == 'l')
	{
		if (!data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_player_idle_2, x * TILE, y * TILE);
			data->idle = 1;
			return (0);
		}
		if (data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_player_idle_1, x * TILE, y * TILE);
			data->idle = 0;
			return (0);
		}
	}
	return (0);
}

void player_walk(t_data *data)
{
	int	floor;

	floor = data->map.player.x;
	if (data->direc == 'r')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.player.y * TILE);
		data->map.player.x += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.player_walk_1, data->map.player.x * TILE - (TILE / 5), data->map.player.y * TILE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.player.y * TILE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.player_walk_2, data->map.player.x * TILE, data->map.player.y * TILE);
	}
	if (data->direc == 'l')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.player.y * TILE);
		data->map.player.x -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.r_player_walk_1, data->map.player.x * TILE + (TILE / 5), data->map.player.y * TILE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.floor, floor * TILE, data->map.player.y * TILE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.r_player_walk_2, data->map.player.x * TILE, data->map.player.y * TILE);
	}
}	