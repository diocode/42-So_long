/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:18:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/04 14:22:57 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	player_idle_l(t_data *data, int x, int y)
{
	if (!data->idle)
	{
		put_tile(data, "./textures/r_player_idle_2.xpm",
				x * SIZE, y * SIZE);
		data->idle = 1;
		return ;
	}
	if (data->idle)
	{
		put_tile(data, "./textures/r_player_idle_1.xpm",
				x * SIZE, y * SIZE);
		data->idle = 0;
		return ;
	}
}

static void	player_idle_r(t_data *data, int x, int y)
{
	if (!data->idle)
	{
		put_tile(data, "./textures/player_idle_2.xpm",
				x * SIZE, y * SIZE);
		data->idle = 1;
		return ;
	}
	if (data->idle)
	{
		put_tile(data, "./textures/player_idle_1.xpm",
				x * SIZE, y * SIZE);
		data->idle = 0;
		return ;
	}
}

int	player_idle(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player.x;
	y = data->map->player.y;
	if (data->loop < 50000)
	{
		data->loop++;
		return (0);
	}
	data->loop = 0;
	if (data->direc == 'r')
		player_idle_r(data, x, y);
	if (data->direc == 'l')
		player_idle_l(data, x, y);
	return (0);
}
