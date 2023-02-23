/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:02:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/23 16:57:52 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	comp_check_check_check(t_map *map, int start_exit)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	if (start_exit != 2)
		return (1);
	if (map->collect < 1)
		return (1);
	str = "01CEP";
	y = -1;
	while (++y < map->lines)
	{
		x = -1;
		while (map->layout[y][++x] != '\n' && map->layout[y][x] != '\0')
		{
			i = -1;
			while (str[++i])
				if (map->layout[y][x] == str[i])
					break ;
			if (i == 5)
				return (1);
		}
	}
	return (0);
}

int	comp_check_check(t_map *map, int x, int y)
{
	int	start_exit;

	start_exit = 0;
	if (map->layout[y][x] == 'C')
		map->collect++;
	if (map->layout[y][x] == 'P')
	{
		map->start.x = x;
		map->start.y = y;
		start_exit++;
	}
	if (map->layout[y][x] == 'E')
	{
		map->exit.x = x;
		map->exit.y = y;
		start_exit++;
	}
	return (start_exit);
}

int	comp_check(t_map *map)
{
	int	start_exit;
	int	x;
	int	y;

	map->collect = 0;
	start_exit = 0;
	y = -1;
	while (map->layout[++y])
	{
		x = -1;
		while (map->layout[y][++x])
			start_exit += comp_check_check(map, x, y);
	}
	return (comp_check_check_check(map, start_exit));
}

int	wall_check(t_map *map)
{	
	int	y;
	int	x;

	y = 0;
	while (y < map->lines)
	{
		x = -1;
		if (y == 0 || y == map->lines - 1)
		{
			while (map->layout[y][++x] != '\n' && map->layout[y][x] != '\0')
			{
				if (map->layout[y][x] != '1')
					return (1);
			}
			y++;
		}
		else
		{
			if (map->layout[y][0] != '1'
				|| map->layout[y][ft_strlen(map->layout[y]) - 2] != '1')
				return (1);
			y++;
		}
	}
	return (0);
}

int	dimension_check(t_map *map)
{
	int	len;
	int	x;

	map->len = strlen_so_long(map->layout[0]);
	len = 0;
	x = 1;
	while (map->layout[x])
	{
		len = strlen_so_long(map->layout[x]);
		if (len == map->len)
			x++;
		else
			return (1);
	}
	return (0);
}
