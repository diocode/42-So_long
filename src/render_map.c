/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:04 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/27 10:27:28 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_wall_corner(t_data *data, int y, int x)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[0], x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[6], x * SIZE, y * SIZE);
	if (y == 0 && x == data->map->len - 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[1], x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x == data->map->len - 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[7], x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x > 0 && x < data->map->len - 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[4], x * SIZE, y * SIZE);
}

void	render_wall_border(t_data *data, int y, int x)
{
	if (y == 0 && x > 0 && x < data->map->len - 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[2], x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x > 0 && x < data->map->len - 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[8], x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[5], x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x == data->map->len - 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[3], x * SIZE, y * SIZE);
}

void	render_tile(t_data *data, int y, int x)
{
	if (data->map->layout[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[10], x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[12], x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[9], x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles[11], x * SIZE, y * SIZE);
}

int	render_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map->layout[++y])
	{
		x = -1;
		while (data->map->layout[y][++x])
		{
			if (data->map->layout[y][x] == '1')
			{
				render_wall_corner(data, y, x);
				render_wall_border(data, y, x);
			}
			else
				render_tile(data, y, x);
		}
	}
	return (0);
}
