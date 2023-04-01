/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 14:59:24 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    put_tile(t_data *data, char *tile, int x, int y)
{
	if (data->img.mlx_img)
    {
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
        data->img.mlx_img = 0;
    }
    data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
		tile, &data->tile.x, &data->tile.y);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, x, y);
}

void	nbr_moves_animation(t_data	*data)
{
	data->moves++;
	if (data->moves > 99 && data->moves <= 999)
		put_tile(data, data->nbr[data->moves / 100],
				data->map->len / 2 * SIZE - 32, data->map->lines * SIZE);
	if (data->moves > 9 && data->moves <= 999)
	{
		if (data->moves > 99 && data->moves <= 999)
			put_tile(data, data->nbr[(data->moves / 10) % 10],
					data->map->len / 2 * SIZE, data->map->lines * SIZE);
		else
			put_tile(data, data->nbr[data->moves / 10],
					data->map->len / 2 * SIZE, data->map->lines * SIZE);
	}
	put_tile(data, data->nbr[data->moves % 10],
			data->map->len / 2 * SIZE + 32, data->map->lines * SIZE);
}

void	exit_anim(t_data *data)
{
	put_tile(data, "./textures/exit_2.xpm", data->map->exit.x * SIZE,
			data->map->exit.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/exit_3.xpm", data->map->exit.x * SIZE,
			data->map->exit.y * SIZE);
	usleep(300000);
	put_tile(data, "./textures/exit_4.xpm", data->map->exit.x * SIZE,
			data->map->exit.y * SIZE);
	usleep(300000);
}
