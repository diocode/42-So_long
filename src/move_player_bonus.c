/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/09 15:59:16 by digoncal         ###   ########.fr       */
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.floor, data->map.player.x * TILE, data->map.player.y * TILE);
		data->map.player.y -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.player, data->map.player.x * TILE, data->map.player.y * TILE);
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.floor, data->map.player.x * TILE, data->map.player.y * TILE);
		data->map.player.y += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.player, data->map.player.x * TILE, data->map.player.y * TILE);
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.floor, data->map.player.x * TILE, data->map.player.y * TILE);
		data->map.player.x += 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.player, data->map.player.x * TILE, data->map.player.y * TILE);
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.floor, data->map.player.x * TILE, data->map.player.y * TILE);
		data->map.player.x -= 1;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.tiles.player, data->map.player.x * TILE, data->map.player.y * TILE);
		data->moves++;
		ft_printf("\033[1;32mMOVES:\033[0m%i\n", data->moves);
	}
}
