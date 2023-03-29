/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/29 15:52:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	start_anim(t_data *data)
{
	put_tile(data, "./textures/start_1.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(600000);
	put_tile(data, "./textures/start_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/start_3.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/start_4.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
	usleep(300000);
}

void	exit_anim(t_data *data)
{
	put_tile(data, "./textures/exit_2.xpm", data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/exit_3.xpm", data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/exit_4.xpm", data->map->exit.x * SIZE, data->map->exit.y * SIZE);
	usleep(300000);
}

void	atk(t_data *data)
{
	if (data->atk == 0)
		return ;
	if (data->atk == 'r')
	{
		put_tile(data, "./textures/atk_1.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/atk_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/atk_3.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/atk_4.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(250000);
	}
	if (data->atk == 'l')
	{
		put_tile(data, "./textures/r_atk_1.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/r_atk_2.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/r_atk_3.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/r_atk_4.xpm", data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(250000);
	}
	data->atk = 0;
}