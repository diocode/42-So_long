/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:48:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/29 15:30:28 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_enemy(t_data *data)
{
	int	x;
	int	y;
	int	enemies;

	y = -1;
	while (data->map->layout[++y])
	{
		x = -1;
		while (data->map->layout[y][++x])
			if (data->map->layout[y][x] == '0')
				data->map->zero++;
	}

	data->map->enemies = data->map->zero / 20;
	if (data->map->enemies == 0)
		data->map->enemies = 1;
	data->map->enemy_x = ft_calloc(data->map->enemies, sizeof(int));
	data->map->enemy_y = ft_calloc(data->map->enemies, sizeof(int));
	if (!data->map->enemy_x || !data->map->enemy_y)
		free_data(data);
	enemies = data->map->enemies;
	while (enemies >= 0)
	{
		x = 0;
		y = 0;
		while (data->map->layout[y][x] != '0')
		{
			x = rand() % (data->map->len - 1);
			y = rand() % (data->map->lines - 1);
		}
		data->map->enemy_x[enemies] = x;
		data->map->enemy_y[enemies] = y;
		enemies--;
	}
}

void	init_null(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->moves = 0;
	data->loop = 0;
	data->idle = 0;
	data->finish = 0;
	data->direc = 'r';
	data->atk = 0;
	data->map->layout = 0;
	data->map->valid = 0;
	data->map->lines = 0;
	data->map->len = 0;
	data->map->collect = 0;
	data->map->gathered = 0;
	data->map->gathered = 0;
	data->map->player.y = 0;
	data->map->player.x = 0;
	data->map->exit.y = 0;
	data->map->exit.x = 0;
	data->map->enemy_x = 0;
	data->map->enemy_y = 0;
}

t_data	*init_data(void)
{
	t_data	*data;
	
	srand(time(NULL));
	data = malloc(sizeof(t_data));
	if (!data)
		return (data);
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
	return (data);
}
