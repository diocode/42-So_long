/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 15:41:08 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	if (data->map->layout[data->map->player.y - 1][data->map->player.x] == 'C')
	{
		data->map->gathered--;
		data->map->layout[data->map->player.y - 1][data->map->player.x] = '0';
	}
	if (data->map->layout[data->map->player.y - 1][data->map->player.x] == '1'
		|| (data->map->layout[data->map->player.y - 1]
			[data->map->player.x] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[10],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->map->player.y -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[9],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	if (data->map->layout[data->map->player.y + 1][data->map->player.x] == 'C')
	{
		data->map->gathered--;
		data->map->layout[data->map->player.y + 1][data->map->player.x] = '0';
	}
	if (data->map->layout[data->map->player.y + 1][data->map->player.x] == '1'
		|| (data->map->layout[data->map->player.y + 1]
			[data->map->player.x] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[10],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->map->player.y += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[9],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_right(t_data *data)
{
	if (data->map->layout[data->map->player.y][data->map->player.x + 1] == 'C')
	{
		data->map->gathered--;
		data->map->layout[data->map->player.y][data->map->player.x + 1] = '0';
	}	
	if (data->map->layout[data->map->player.y][data->map->player.x + 1] == '1'
		|| (data->map->layout[data->map->player.y]
			[data->map->player.x + 1] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[10],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->map->player.x += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[9],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}

void	move_left(t_data *data)
{		
	if (data->map->layout[data->map->player.y][data->map->player.x - 1] == 'C')
	{
		data->map->gathered--;
		data->map->layout[data->map->player.y][data->map->player.x - 1] = '0';
	}	
	if (data->map->layout[data->map->player.y][data->map->player.x - 1] == '1'
		|| (data->map->layout[data->map->player.y]
			[data->map->player.x - 1] == 'E' && data->map->gathered != 0))
		return ;
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[10],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->map->player.x -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles[9],
			data->map->player.x * SIZE, data->map->player.y * SIZE);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}
