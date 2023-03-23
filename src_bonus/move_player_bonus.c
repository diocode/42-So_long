/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 10:25:50 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_data *data)
{
	if (data->map.layout[data->map.player.y - 1][data->map.player.x] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
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
		atk(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	if (data->map.layout[data->map.player.y + 1][data->map.player.x] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
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
		atk(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_right(t_data *data)
{
		data->direc = 'r';
	if (data->map.layout[data->map.player.y][data->map.player.x + 1] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map.gathered--;
		data->map.layout[data->map.player.y][data->map.player.x + 1] = '0';
	}	
	if (data->map.layout[data->map.player.y][data->map.player.x + 1] == '1'
		|| (data->map.layout[data->map.player.y][data->map.player.x + 1] == 'E' && data->map.gathered != 0))
		return ;
	else
	{
		player_walk_x(data);
		atk(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);	
	}
}

void	move_left(t_data *data)
{		
	data->direc = 'l';
	if (data->map.layout[data->map.player.y][data->map.player.x - 1] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map.gathered--;
		data->map.layout[data->map.player.y][data->map.player.x - 1] = '0';
	}	
	if (data->map.layout[data->map.player.y][data->map.player.x - 1] == '1'
		|| (data->map.layout[data->map.player.y][data->map.player.x - 1] == 'E' && data->map.gathered != 0))
		return ;
	else
	{
		player_walk_x(data);
		atk(data);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}
