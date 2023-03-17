/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/17 16:17:28 by digoncal         ###   ########.fr       */
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

void	exit_anim(t_data *data)
{
	int	t;
	
	t = 0;
	while(t < 40000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_1, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
	t = 0;
	while(t < 40000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_2, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
	t = 0;
	while(t < 40000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_3, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
	t = 0;
	while(t < 40000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_4, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
	t = 0;
	while(t < 40000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_5, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
	t = 0;
	while(t < 40000)
	{	
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_6, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
	t = 0;
	while(t < 40000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.tiles.exit_7, data->map.exit.x * TILE, data->map.exit.y * TILE);
		t++;
	}
}

void	atk(t_data *data)
{
	int	t;
	if (data->atk == 0)
		return ;
	if (data->atk == 'r')
	{
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.atk_1, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.atk_2, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.atk_3, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.atk_4, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.atk_5, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
	}
	if (data->atk == 'l')
	{
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_atk_1, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_atk_2, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_atk_3, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_atk_4, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
		t = 0;
		while(t < 30000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.tiles.r_atk_5, data->map.player.x * TILE, data->map.player.y * TILE);
			t++;
		}
	}
	data->atk = 0;
}