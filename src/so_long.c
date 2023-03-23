/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 15:43:00 by digoncal         ###   ########.fr       */
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
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->tile.y = SIZE;
	data->tile.x = SIZE;
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
	return (data);
}

int	file_check(char *str)
{
	char	*ber;

	str = ft_strrchr(str, '.');
	ber = ".ber";
	return (ft_strncmp(str, ber, 4));
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || file_check(av[1]) != 0)
		return (1);
	data = init_data();
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	init_img1(data);
	init_img2(data);
	map_check(av[1], data);
	if (data->map->valid != 0 || !data->map->layout)
	{
		free_game(data);
		return (1);
	}
	render(data);
	return (0);
}
