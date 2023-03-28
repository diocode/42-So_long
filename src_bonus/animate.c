/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:18:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/28 23:38:22 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	player_idle(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player.x;
	y = data->map->player.y;
	if (data->loop < 20000)
	{
		data->loop++;
		return (0);
	}
	data->loop = 0;
	if (data->direc == 'r' || data->direc == 'a' || data->direc == 'x')
	{
		data->direc = 'r';
		if (!data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles[21], x * SIZE, y * SIZE);
			data->idle = 1;
			return (0);
		}
		if (data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles[20], x * SIZE, y * SIZE);
			data->idle = 0;
			return (0);
		}
	}
	if (data->direc == 'l' || data->direc == 'b' || data->direc == 'z')
	{
		data->direc = 'l';
		if (!data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles[23], x * SIZE, y * SIZE);
			data->idle = 1;
			return (0);
		}
		if (data->idle)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles[22], x * SIZE, y * SIZE);
			data->idle = 0;
			return (0);
		}
	}
	return (0);
}

void player_walk(t_data *data )
{
	if (data->direc == 'r')
		walk_right(data);
	if (data->direc == 'l')
		walk_left(data);
	/*up*/
	if (data->direc == 'a')
		walk_up_r(data);
	if (data->direc == 'b')
		walk_up_l(data);
	/*down*/
	if (data->direc == 'x')
		walk_down_r(data);
	if (data->direc == 'z')
		walk_down_l(data);
}	

void	walk_right(t_data *data)
{
	int	floor;

	floor = data->map->player.x;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->player.y * SIZE);
	data->map->player.x += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[24], data->map->player.x * SIZE - (SIZE / 5), data->map->player.y * SIZE);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[25], data->map->player.x * SIZE, data->map->player.y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->player.y * SIZE);
}

void	walk_left(t_data *data)
{
	int	floor;

	floor = data->map->player.x;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->player.y * SIZE);
	data->map->player.x -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[26], data->map->player.x * SIZE + (SIZE / 5), data->map->player.y * SIZE);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[27], data->map->player.x * SIZE, data->map->player.y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], floor * SIZE, data->map->player.y * SIZE);
}

void	walk_up_r(t_data *data)
{
	int	floor;
	
	floor = data->map->player.y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
	data->map->player.y -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[24], data->map->player.x * SIZE, data->map->player.y * SIZE + (SIZE / 5));
	usleep(300000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[25], data->map->player.x * SIZE, data->map->player.y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);	
}

void	walk_up_l(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
	data->map->player.y -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[26], data->map->player.x * SIZE, data->map->player.y * SIZE + (SIZE / 5));
	usleep(300000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[27], data->map->player.x * SIZE, data->map->player.y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
}

void	walk_down_r(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
	data->map->player.y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[24], data->map->player.x * SIZE, data->map->player.y * SIZE - (SIZE / 5));
	usleep(300000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[25], data->map->player.x * SIZE, data->map->player.y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
}

void	walk_down_l(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
	data->map->player.y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[26], data->map->player.x * SIZE, data->map->player.y * SIZE - (SIZE / 5));
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[27], data->map->player.x * SIZE, data->map->player.y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], data->map->player.x * SIZE, floor * SIZE);
}