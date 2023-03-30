/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:18:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/30 00:33:25 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	player_idle(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player.x;
	y = data->map->player.y;
	if (data->loop < 5000)
	{
		data->loop++;
		return (0);
	}
	data->loop = 0;
	if (data->direc == 'r')
	{
		if (!data->idle)
		{
			put_tile(data, "./textures/player_idle_2.xpm", x * SIZE, y * SIZE);
			data->idle = 1;
			return (0);
		}
		if (data->idle)
		{
			put_tile(data, "./textures/player_idle_1.xpm", x * SIZE, y * SIZE);
			data->idle = 0;
			return (0);
		}
	}
	if (data->direc == 'l')
	{

		if (!data->idle)
		{
			put_tile(data, "./textures/r_player_idle_2.xpm", x * SIZE, y * SIZE);
			data->idle = 1;
			return (0);
		}
		if (data->idle)
		{
			put_tile(data, "./textures/r_player_idle_1.xpm", x * SIZE, y * SIZE);
			data->idle = 0;
			return (0);
		}
	}
	return (0);
}	

void	walk_right(t_data *data)
{
	int	floor;

	floor = data->map->player.x;
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->player.y * SIZE);
	data->map->player.x += 1;
	put_tile(data, "./textures/player_walk_1.xpm", data->map->player.x * SIZE - (SIZE / 2), data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->player.y * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_walk_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->player.y * SIZE);
	usleep(100000);
}

void	walk_left(t_data *data)
{
	int	floor;

	floor = data->map->player.x;
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->player.y * SIZE);
	data->map->player.x -= 1;
	put_tile(data, "./textures/r_player_walk_1.xpm", data->map->player.x * SIZE + (SIZE / 2), data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->player.y * SIZE);
	usleep(150000);
	put_tile(data, "./textures/r_player_walk_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", floor * SIZE, data->map->player.y * SIZE);
	usleep(100000);
}

void	walk_up(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	data->map->player.y -= 1;
	put_tile(data, "./textures/player_up_1.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE + ((SIZE / 3) * 2));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_up_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE + (SIZE / 3));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_up_3.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	usleep(100000);
}

void	walk_down(t_data *data)
{
	int	floor;

	floor = data->map->player.y;
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	data->map->player.y += 1;
	put_tile(data, "./textures/player_down_1.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE - ((SIZE / 3) * 2));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_down_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE - (SIZE / 3));
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	usleep(150000);
	put_tile(data, "./textures/player_down_3.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	put_tile(data, "./textures/floor.xpm", data->map->player.x * SIZE, floor * SIZE);
	usleep(100000);
}

void    put_tile(t_data *data, char *tile, int x, int y)
{
	/*if (data->img.mlx_img)
    {
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
        data->img.mlx_img = 0;
    }*/
    data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
		tile, &data->tile.x, &data->tile.y);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, x, y);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
        data->img.mlx_img = 0;
}
