/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:04 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/30 01:54:39 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_wall_corner(t_data *data, int y, int x)
{
	if (y == 0 && x == 0)
		put_tile(data, "./textures/wall_u_l.xpm", x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x == 0)
		put_tile(data, "./textures/wall_d_l.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x == data->map->len - 1)
		put_tile(data, "./textures/wall_u_r.xpm", x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x == data->map->len - 1)
		put_tile(data, "./textures/wall_d_r.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x > 0 && x < data->map->len - 1)
		put_tile(data, "./textures/wall_m.xpm", x * SIZE, y * SIZE);
}

void	render_wall_border(t_data *data, int y, int x)
{
	if (y == 0 && x > 0 && x < data->map->len - 1)
		put_tile(data, "./textures/wall_u.xpm", x * SIZE, y * SIZE);
	if (y == data->map->lines - 1 && x > 0 && x < data->map->len - 1)
		put_tile(data, "./textures/wall_d.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 &&  x == 0)
		put_tile(data, "./textures/wall_l.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < data->map->lines - 1 && x == data->map->len - 1)
		put_tile(data, "./textures/wall_r.xpm", x * SIZE, y * SIZE);
}

void	render_tile(t_data *data, int y, int x)
{
	if (data->map->layout[y][x] == '0')
		put_tile(data, "./textures/floor.xpm", x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'C')
		put_tile(data, "./textures/collect_idle_1.xpm", x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'P')
		put_tile(data, "./textures/player_idle_1.xpm", x * SIZE, y * SIZE);
	if (data->map->layout[y][x] == 'E')
		put_tile(data, "./textures/exit_1.xpm", x * SIZE, y * SIZE);
}

void	render_nbr(t_data *data)
{
	put_tile(data, "./textures/0.xpm", data->map->len / 2 * SIZE + 32, data->map->lines * SIZE);
	put_tile(data, "./textures/0.xpm", data->map->len / 2 * SIZE, data->map->lines * SIZE);
	put_tile(data, "./textures/0.xpm", data->map->len / 2 * SIZE - 32, data->map->lines * SIZE);
}

int render_map(t_data *data)
{
	int x;
	int y;

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
	render_nbr(data);
	return (0);
}

int	render_win(t_data *data)
{
	int	width;
	int	height;

	width = data->map->len * SIZE;
	height = (data->map->lines + 1) * SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long_bonus");
	if (!data->win_ptr)
		{
			free(data->win_ptr);
			return (1);
		}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, height, width);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}
