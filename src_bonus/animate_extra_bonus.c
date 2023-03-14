/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/14 11:07:02 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start(t_data *data)
{
	int	t;
	
	t = 0;
	while(t < 90000)
	{	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.start_1, data->map.player.x * TILE, data->map.player.y * TILE);
		t++;
	}
	t = 0;
	while(t < 90000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.start_2, data->map.player.x * TILE, data->map.player.y * TILE);
		t++;
	}
	t = 0;
	while(t < 80000)
	{	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.start_3, data->map.player.x * TILE, data->map.player.y * TILE);
		t++;
	}
	t = 0;
	while(t < 90000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.start_4, data->map.player.x * TILE, data->map.player.y * TILE);
		t++;
	}
}