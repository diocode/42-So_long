/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:04 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/03 12:54:48 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall_border(t_data *data, int x, int y)
{
	if (y == 0 && x > 0 && x < data->map.len - 1)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_u.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y == data->map.lines - 1 && x > 0 && x < data->map.len - 1)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_d.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y > 0 && y < data->map.lines - 1 && x == 0)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_l.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y > 0 && y < data->map.lines - 1 && x == data->map.len - 1)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_r.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
}

void	render_wall_corner(t_data *data, int x, int y)
{
	if (y == 0 && x == 0)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_u_l.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y == 0 && x == data->map.len - 1)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_u_r.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y == data->map.lines - 1 && x == 0)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_d_l.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y == data->map.lines - 1 && x == data->map.len - 1)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_d_r.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (y > 0 && y < data->map.lines - 1 && x > 0 && x < data->map.len - 1)
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/wall_m.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
}

void	render_tile(t_data *data, int x, int y)
{
	if (data->map.layout[y][x] == '0')
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (data->map.layout[y][x] == 'P')
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (data->map.layout[y][x] == 'E')
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/exit.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
	if (data->map.layout[y][x] == 'C')
	{
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/collect.xpm", &data->tile.x, &data->tile.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x * TILE, y * TILE);
	}
}

int render_map(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (data->map.layout[++y])
	{
		x = -1;
		while (data->map.layout[y][++x])
		{
			if (data->map.layout[y][x] == '1')
			{
				// MAKE  SURE THE PROG DOESNT SEG FAULT WHEN THE IMG DONT EXIST
				render_wall_corner(data, x, y);
				render_wall_border(data, x, y);
			}
			render_tile(data, x, y);
		}
	}
	return (0);
}

int	render_win(t_data *data)
{
	int	width;
	int	height;

	width = data->map.len * TILE;
	height = data->map.lines * TILE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");
	if (!data->win_ptr)
		{
			free(data->win_ptr);
			return (1);
		}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, height, width);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}
