/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/13 13:38:18 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data)
{
	if (data->map.layout[data->map.player.y - 1][data->map.player.x] == 'C')
	{
		data->map.gathered--;
		data->map.layout[data->map.player.y - 1][data->map.player.x] = '0';
	}
	if (data->map.layout[data->map.player.y - 1][data->map.player.x] == '1'
		|| (data->map.layout[data->map.player.y - 1][data->map.player.x] == 'E' 
			&& data->map.gathered != 0))
		return ;
	else
	{
		if (data->direc == 'r')
			data->direc = 'a';
		else if (data->direc == 'l')
			data->direc = 'b';
		player_walk_y(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	if (data->map.layout[data->map.player.y + 1][data->map.player.x] == 'C')
	{
		data->map.gathered--;
		data->map.layout[data->map.player.y + 1][data->map.player.x] = '0';
	}
	if (data->map.layout[data->map.player.y + 1][data->map.player.x] == '1'
		|| (data->map.layout[data->map.player.y + 1][data->map.player.x] == 'E' && data->map.gathered != 0))
		return ;
	else
	{
		if (data->direc == 'r')
			data->direc = 'x';
		if (data->direc == 'l')
			data->direc = 'z';
		player_walk_y(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_right(t_data *data)
{
	if (data->map.layout[data->map.player.y][data->map.player.x + 1] == 'C')
	{
		data->map.gathered--;
		data->map.layout[data->map.player.y][data->map.player.x + 1] = '0';
	}	
	if (data->map.layout[data->map.player.y][data->map.player.x + 1] == '1'
		|| (data->map.layout[data->map.player.y][data->map.player.x + 1] == 'E' && data->map.gathered != 0))
		return ;
	else
	{
		data->direc = 'r';
		player_walk_x(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);	
	}
}

void	move_left(t_data *data)
{		
	if (data->map.layout[data->map.player.y][data->map.player.x - 1] == 'C')
	{
		data->map.gathered--;
		data->map.layout[data->map.player.y][data->map.player.x - 1] = '0';
	}	
	if (data->map.layout[data->map.player.y][data->map.player.x - 1] == '1'
		|| (data->map.layout[data->map.player.y][data->map.player.x - 1] == 'E' && data->map.gathered != 0))
		return ;
	else
	{
		data->direc = 'l';
		player_walk_x(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}
