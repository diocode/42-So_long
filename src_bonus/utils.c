/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:10:14 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 15:24:13 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	strlen_solong(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str [i] != '\n')
		i++;
	return (i);
}

int	file_check(char *str)
{
	char	*ber;

	str = ft_strrchr(str, '.');
	if (!str)
	{
		ft_printf("\033[1;31mError:\033[0m Invalid File\n");
		return (1);
	}
	ber = ".ber";
	if (ft_strncmp(str, ber, 4) != 0)
	{
		ft_printf("\033[1;31mError:\033[0m Invalid File\n");
		return (1);
	}
	return (0);
}

void	enemy_pos(t_data *data)
{
	int	enemies;
	int	stuck;

	enemies = data->map->enemies;
	while (--enemies >= 0)
	{
		stuck = data->map->enemy_x[enemies] + data->map->enemy_y[enemies];
		move_enemy(data, enemies);
		if (stuck == data->map->enemy_x[enemies]
				+ data->map->enemy_y[enemies])
			enemies++;
	}
}
