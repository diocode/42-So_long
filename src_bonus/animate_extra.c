/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/28 23:05:07 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	start_anim(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[10], data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(600000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[11], data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(300000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[12], data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(300000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[13], data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(300000);
}

void	exit_anim(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[14], data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(500000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[15], data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(500000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[16], data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(500000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[17], data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(500000);
}

void	atk(t_data *data)
{
	if (data->atk == 0)
		return ;
	if (data->atk == 'r')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[32], data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[33], data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->tiles[34], data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
	}
	if (data->atk == 'l')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[35], data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[36], data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->tiles[37], data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
	}
	data->atk = 0;
}