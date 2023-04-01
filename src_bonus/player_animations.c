/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:04:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 14:09:54 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	atk2(t_data *data)
{
	if (data->atk == 'l')
	{
		put_tile(data, "./textures/r_atk_1.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/r_atk_2.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/r_atk_3.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/r_atk_4.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(250000);
	}
}

void	atk1(t_data *data)
{
	if (data->atk == 0)
		return ;
	if (data->atk == 'r')
	{
		put_tile(data, "./textures/atk_1.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/atk_2.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/atk_3.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(170000);
		put_tile(data, "./textures/atk_4.xpm", data->map->player.x * SIZE,
				data->map->player.y * SIZE);
		usleep(250000);
	}
	atk2(data);
	data->atk = 0;
}

void	start_anim(t_data *data)
{
	put_tile(data, "./textures/start_1.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	usleep(600000);
	put_tile(data, "./textures/start_2.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/start_3.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/start_4.xpm", data->map->player.x * SIZE,
			data->map->player.y * SIZE);
	usleep(300000);
}

void	kill_player(t_data *data)
{
	if (data->direc == 'r')
	{
		put_tile(data, "./textures/player_d_1.xpm",
				data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(450000);
		put_tile(data, "./textures/player_d_2.xpm",
				data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
		put_tile(data, "./textures/r_player_d_3.xpm",
				data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
	}
	if (data->direc == 'l')
	{
		put_tile(data, "./textures/r_player_d_1.xpm",
				data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(450000);
		put_tile(data, "./textures/r_player_d_2.xpm",
				data->map->player.x * SIZE, data->map->player.y * SIZE);
		put_tile(data, "./textures/r_player_d_3.xpm",
				data->map->player.x * SIZE, data->map->player.y * SIZE);
		usleep(300000);
	}
	ft_printf("\033[1;31m= GAME OVER =\033[0m\n");
	ft_quit(data);
}
