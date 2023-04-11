/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:18 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/06 10:57:45 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	enemy_move_up(t_data *data, int enemies, int *x, int *y)
{
	if (data->map->layout[y[enemies] - 1][x[enemies]] == '1'
			|| data->map->layout[y[enemies] - 1][x[enemies]] == 'C'
			|| data->map->layout[y[enemies] - 1][x[enemies]] == 'E'
			|| data->map->layout[y[enemies] - 1][x[enemies]] == 'X')
		return ;
	data->map->layout[y[enemies]][x[enemies]] = '0';
	enemy_up(data, enemies);
	data->map->layout[y[enemies]][x[enemies]] = 'X';
}

static void	enemy_move_down(t_data *data, int enemies, int *x, int *y)
{
	if (data->map->layout[y[enemies] + 1][x[enemies]] == '1'
			|| data->map->layout[y[enemies] + 1][x[enemies]] == 'C'
			|| data->map->layout[y[enemies] + 1][x[enemies]] == 'E'
			|| data->map->layout[y[enemies] + 1][x[enemies]] == 'X')
		return ;
	data->map->layout[y[enemies]][x[enemies]] = '0';
	enemy_down(data, enemies);
	data->map->layout[y[enemies]][x[enemies]] = 'X';
}

static void	enemy_move_right(t_data *data, int enemies, int *x, int *y)
{
	if (data->map->layout[y[enemies]][x[enemies] + 1] == '1'
			|| data->map->layout[y[enemies]][x[enemies] + 1] == 'C'
			|| data->map->layout[y[enemies]][x[enemies] + 1] == 'E'
			|| data->map->layout[y[enemies]][x[enemies] + 1] == 'X')
		return ;
	data->map->layout[y[enemies]][x[enemies]] = '0';
	enemy_right(data, enemies);
	data->map->layout[y[enemies]][x[enemies]] = 'X';
}

static void	enemy_move_left(t_data *data, int enemies, int *x, int *y)
{
	if (data->map->layout[y[enemies]][x[enemies] - 1] == '1'
			|| data->map->layout[y[enemies]][x[enemies] - 1] == 'C'
			|| data->map->layout[y[enemies]][x[enemies] - 1] == 'E'
			|| data->map->layout[y[enemies]][x[enemies] - 1] == 'X')
		return ;
	data->map->layout[y[enemies]][x[enemies]] = '0';
	enemy_left(data, enemies);
	data->map->layout[y[enemies]][x[enemies]] = 'X';
}

void	move_enemy(t_data *data, int enemies)
{
	int	*x;
	int	*y;
	int	n;

	x = data->map->enemy_x;
	y = data->map->enemy_y;
	n = (rand() % 4) + 1;
	if (n == 1)
		enemy_move_up(data, enemies, x, y);
	if (n == 2)
		enemy_move_down(data, enemies, x, y);
	if (n == 3)
		enemy_move_right(data, enemies, x, y);
	if (n == 4)
		enemy_move_left(data, enemies, x, y);
	if (x[enemies] == data->map->player.x && y[enemies] == data->map->player.y)
		kill_player(data);
}
