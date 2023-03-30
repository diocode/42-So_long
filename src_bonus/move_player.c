/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/30 01:55:55 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_data *data)
{
	if (data->map->layout[data->map->player.y - 1][data->map->player.x] == 'X')
		kill_player(data);
	if (data->map->layout[data->map->player.y - 1][data->map->player.x] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[data->map->player.y - 1][data->map->player.x] = '0';
	}
	if (data->map->layout[data->map->player.y - 1][data->map->player.x] == '1'
		|| (data->map->layout[data->map->player.y - 1][data->map->player.x] == 'E' 
			&& data->map->gathered != 0))
		return ;
	else
	{
		walk_up(data);
		atk(data);
		data->moves++;
		render_moves_nbr(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	if (data->map->layout[data->map->player.y + 1][data->map->player.x] == 'X')
		kill_player(data);
	if (data->map->layout[data->map->player.y + 1][data->map->player.x] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[data->map->player.y + 1][data->map->player.x] = '0';
	}
	if (data->map->layout[data->map->player.y + 1][data->map->player.x] == '1'
		|| (data->map->layout[data->map->player.y + 1][data->map->player.x] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_down(data);
		atk(data);
		data->moves++;
		render_moves_nbr(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_right(t_data *data)
{
	if (data->map->layout[data->map->player.y][data->map->player.x + 1] == 'X')
		kill_player(data);
	data->direc = 'r';
	if (data->map->layout[data->map->player.y][data->map->player.x + 1] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[data->map->player.y][data->map->player.x + 1] = '0';
	}	
	if (data->map->layout[data->map->player.y][data->map->player.x + 1] == '1'
		|| (data->map->layout[data->map->player.y][data->map->player.x + 1] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_right(data);
		atk(data);
		data->moves++;
		render_moves_nbr(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);	
	}
}

void	move_left(t_data *data)
{		
	if (data->map->layout[data->map->player.y][data->map->player.x - 1] == 'X')
		kill_player(data);
	data->direc = 'l';
	if (data->map->layout[data->map->player.y][data->map->player.x - 1] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[data->map->player.y][data->map->player.x - 1] = '0';
	}	
	if (data->map->layout[data->map->player.y][data->map->player.x - 1] == '1'
		|| (data->map->layout[data->map->player.y][data->map->player.x - 1] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_left(data);
		atk(data);
		data->moves++;
		render_moves_nbr(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	render_moves_nbr(t_data	*data)
{
	if (data->moves <= 9)
		put_tile(data, "./textures/1.xpm", data->map->len / 2 *SIZE +32, data->map->lines * SIZE);
	if (data->moves > 9 && data->moves <= 99)
		put_tile(data, "./textures/1.xpm", data->map->len/2 * SIZE, data->map->lines * SIZE);
	if (data->moves > 99 && data->moves <= 999)
		put_tile(data, "./textures/1.xpm", data->map->len / 2 * SIZE - 32, data->map->lines * SIZE);
}
