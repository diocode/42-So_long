/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:51:58 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 14:52:33 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	validate_arrays (t_data *data)
{
	if (!data->map->enemy_x || !data->map->enemy_y)
	{
		if (data->map->enemy_x)
			free(data->map->enemy_x);
		if (data->map->enemy_x)
			free(data->map->enemy_x);
		return (1);
	}
	return (0);
}

static int	count_zeros (t_data *data)
{
	int	x;
	int	y;
	int zeros;

	zeros = 0;
	y = -1;
	while (data->map->layout[++y])
	{
		x = -1;
		while (data->map->layout[y][++x])
			if (data->map->layout[y][x] == '0')
				zeros++;
	}
	return (zeros);
}

int	init_enemy(t_data *data)
{
	int	x;
	int	y;
	int	enemies;

	data->map->enemies = count_zeros(data) / 20;
	data->map->enemy_x = ft_calloc(data->map->enemies, sizeof(int));
	data->map->enemy_y = ft_calloc(data->map->enemies, sizeof(int));
	if (validate_arrays(data))
		return (1);
	enemies = data->map->enemies;
	while (--enemies >= 0)
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
	}
	return (0);
}
