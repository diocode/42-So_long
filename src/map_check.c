/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:54:52 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/27 23:59:25 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wall_check(t_data *data)
{	
	int	y;
	int	x;

	y = -1;
	while (++y < data->map->lines)
	{
		x = -1;
		if (y == 0 || y == data->map->lines - 1)
		{
			while (data->map->layout[y][++x] != '\n'
				&& data->map->layout[y][x] != '\0')
			{
				if (data->map->layout[y][x] != '1')
					return (1);
			}
		}
		else
		{
			if (data->map->layout[y][0] != '1'
				|| data->map->layout[y]
					[ft_strlen(data->map->layout[y]) - 2] != '1')
				return (1);
		}
	}
	return (0);
}

int	dimension_check(t_data *data)
{
	int	len;
	int	x;

	data->map->len = strlen_solong(data->map->layout[0]);
	len = 0;
	x = 1;
	while (data->map->layout[x])
	{
		len = strlen_solong(data->map->layout[x]);
		if (len == data->map->len)
			x++;
		else
			return (1);
	}
	return (0);
}

int	comp1_check(t_data *data)
{
	int	start_exit;
	int	x;
	int	y;

	data->map->collect = 0;
	start_exit = 0;
	y = -1;
	while (data->map->layout[++y])
	{
		x = -1;
		while (data->map->layout[y][++x])
			start_exit += comp2_check(data, x, y);
	}
	return (comp3_check(data, start_exit));
}

int	path_check(char *file, t_data *data)
{
	char	**layout_cpy;

	layout_cpy = file_to_map(file);
	if (!layout_cpy)
		return (1);
	fill(layout_cpy, data, data->map->player.x, data->map->player.y);
	if (!data->map->exit.y || !data->map->exit.x)
		return (1);
	if (layout_cpy[data->map->exit.y - 1][data->map->exit.x] != 'W'
		&& layout_cpy[data->map->exit.y + 1][data->map->exit.x] != 'W'
		&& layout_cpy[data->map->exit.y][data->map->exit.x - 1] != 'W'
		&& layout_cpy[data->map->exit.y][data->map->exit.x + 1] != 'W'
		&& layout_cpy[data->map->exit.y - 1][data->map->exit.x] != 'G'
		&& layout_cpy[data->map->exit.y + 1][data->map->exit.x] != 'G'
		&& layout_cpy[data->map->exit.y][data->map->exit.x - 1] != 'G'
		&& layout_cpy[data->map->exit.y][data->map->exit.x + 1] != 'G')
		return (1);
	if (data->map->collect != data->map->gathered)
		return (1);
	free_array(layout_cpy);
	return (0);
}

void	map_check(char *file, t_data *data)
{
	data->map->layout = file_to_map(file);
	if (!data->map->layout)
		return ;
	while (data->map->layout[data->map->lines])
		data->map->lines++;
	data->map->valid = dimension_check(data) + wall_check(data);
	data->map->valid += comp1_check(data) + path_check(file, data);
	if (data->map->valid == 0)
		return ;
	else
	{
		ft_printf("\033[1;31mError:\033[0m Invalid Map\n");
		return ;
	}
	return ;
}
