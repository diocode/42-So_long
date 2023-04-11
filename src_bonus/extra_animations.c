/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/11 14:16:17 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_tile(t_data *data, char *tile, int x, int y)
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
	int	i;
	int	digit;
	int	mv;

	data->moves++;
	mv = data->moves;
	i = 0;
	while (i < 6)
	{
		digit = mv % 10;
		mv /= 10;
		if (data->map->len % 2 != 0)
			put_tile(data, data->nbr[digit],
				(data->map->len / 2 * SIZE + 96) - i * 32,
				data->map->lines * SIZE);
		else
			put_tile(data, data->nbr[digit],
				(data->map->len / 2 * SIZE + 64) - i * 32,
				data->map->lines * SIZE);
		i++;
	}
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
