/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:41 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 15:24:18 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_enemies(t_data *data)
{
	int e;
	t_map	*m;

	m = data->map;
	e = -1;
	while (++e < data->map->enemies)
	{
		put_tile(data, "./textures/enemy_1.xpm",
				m->enemy_x[e] * SIZE, m->enemy_y[e] * SIZE);
		data->map->layout[m->enemy_y[e]][m->enemy_x[e]] = 'X';
	}
}

int	render_win(t_data *data)
{
	int	width;
	int	height;

	width = data->map->len * SIZE;
	height = (data->map->lines + 1) * SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width,
					height, "so_long_bonus");
	if (!data->win_ptr)
		{
			free(data->win_ptr);
			return (1);
		}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, height, width);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
					&data->img.line_len, &data->img.endian);
	return (0);
}

int	render(t_data *data)
{
	render_win(data);
	if (!data->win_ptr)
		return (1);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &ft_quit, data);
	mlx_loop_hook(data->mlx_ptr, &player_idle, data);
	render_map(data);
	render_enemies(data);
	start_anim(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
