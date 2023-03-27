/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:31:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/27 23:03:30 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img1(t_data *data)
{
	data->tiles[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u_l.xpm", &data->tile.x, &data->tile.y);
	data->tiles[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u_r.xpm", &data->tile.x, &data->tile.y);
	data->tiles[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u.xpm", &data->tile.x, &data->tile.y);
	data->tiles[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_r.xpm", &data->tile.x, &data->tile.y);
	data->tiles[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_m.xpm", &data->tile.x, &data->tile.y);
	data->tiles[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_l.xpm", &data->tile.x, &data->tile.y);
	data->tiles[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d_l.xpm", &data->tile.x, &data->tile.y);
	data->tiles[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d_r.xpm", &data->tile.x, &data->tile.y);
	data->tiles[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d.xpm", &data->tile.x, &data->tile.y);
}

void	init_img2(t_data *data)
{
	data->tiles[9] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[10] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &data->tile.x, &data->tile.y);
	data->tiles[11] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_4.xpm", &data->tile.x, &data->tile.y);
	data->tiles[12] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collect_idle_1.xpm", &data->tile.x, &data->tile.y);
}

void	init_null(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->img.mlx_img = 0;
	data->moves = 0;
	data->map->layout = 0;
	data->map->valid = 0;
	data->map->lines = 0;
	data->map->len = 0;
	data->map->collect = 0;
	data->map->gathered = 0;
	data->map->player.y = 0;
	data->map->player.x = 0;
	data->map->exit.y = 0;
	data->map->exit.x = 0;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (data);
	data->tiles = malloc(NUM_TILES * sizeof(void *));
	if (!data->tiles)
	{
		free_game(data);
		return (data);
	}
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		free_game(data);
		return (data);
	}
	data->tile.y = SIZE;
	data->tile.x = SIZE;
	init_null(data);
	return (data);
}

t_data	*init(void)
{
	t_data	*data;

	data = init_data();
	if (!data)
	{
		free_game(data);
		return (NULL);
	}
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_game(data);
		return (NULL);
	}
	init_img1(data);
	init_img2(data);
	return (data);
}
