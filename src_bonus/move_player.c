/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/06 10:44:59 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_data *data)
{
	t_point	p;

	p = data->map->player;
	if (data->map->layout[p.y - 1][p.x] == 'X')
		kill_player(data);
	if (data->map->layout[p.y - 1][p.x] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[p.y - 1][p.x] = '0';
	}
	if (data->map->layout[p.y - 1][p.x] == '1'
		|| (data->map->layout[p.y - 1][p.x] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_up(data);
		atk1(data);
		nbr_moves_animation(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	t_point	p;

	p = data->map->player;
	if (data->map->layout[p.y + 1][p.x] == 'X')
		kill_player(data);
	if (data->map->layout[p.y + 1][p.x] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[p.y + 1][p.x] = '0';
	}
	if (data->map->layout[p.y + 1][p.x] == '1'
		|| (data->map->layout[p.y + 1][p.x] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_down(data);
		atk1(data);
		nbr_moves_animation(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_right(t_data *data)
{
	t_point	p;

	p = data->map->player;
	if (data->map->layout[p.y][p.x + 1] == 'X')
		kill_player(data);
	data->direc = 'r';
	if (data->map->layout[p.y][p.x + 1] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[p.y][p.x + 1] = '0';
	}	
	if (data->map->layout[p.y][p.x + 1] == '1'
		|| (data->map->layout[p.y][p.x + 1] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_right(data);
		atk1(data);
		nbr_moves_animation(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_left(t_data *data)
{
	t_point	p;

	p = data->map->player;
	if (data->map->layout[p.y][p.x - 1] == 'X')
		kill_player(data);
	data->direc = 'l';
	if (data->map->layout[p.y][p.x - 1] == 'C')
	{
		if (data->direc == 'r')
			data->atk = 'r';
		else if (data->direc == 'l')
			data->atk = 'l';
		data->map->gathered--;
		data->map->layout[p.y][p.x - 1] = '0';
	}	
	if (data->map->layout[p.y][p.x - 1] == '1'
		|| (data->map->layout[p.y][p.x - 1] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		walk_left(data);
		atk1(data);
		nbr_moves_animation(data);
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}
