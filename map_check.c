/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:54:52 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/22 19:39:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**file_to_map(char *file)
{
	int		lines;
	int		fd;
	int		i;
	char	*gnl;
	char	**map;

	fd = open(file, O_RDONLY);
	map = 0;
	if (fd < 0)
		return (map);
	lines = 0;
	gnl = get_next_line(fd);
	while (gnl && lines++ >= 0)
		gnl = get_next_line(fd);
	close(fd);
	map = (char **)malloc(sizeof(char *) * lines);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (map);
	i = -1;
	while (i++ < lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

void	fill(char **layout_cpy, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->len || y >= map->lines)
		return ;
	if (layout_cpy[y][x] == 'W' || layout_cpy[y][x] == 'E'
		|| layout_cpy[y][x] == '1' || layout_cpy[y][x] == 'G')
		return ;
	if (layout_cpy[y][x] == 'C')
	{	
		layout_cpy[y][x] = 'G';
		map->gathered++;
	}
	else
		layout_cpy[y][x] = 'W';
	fill(layout_cpy, map, x - 1, y);
	fill(layout_cpy, map, x + 1, y);
	fill(layout_cpy, map, x, y - 1);
	fill(layout_cpy, map, x, y + 1);
}

int	path_check(char *file, t_map *map)
{
	char	**layout_cpy;

	layout_cpy = file_to_map(file);
	fill(layout_cpy, map, map->start.x, map->start.y);
	if (!map->exit.y || !map->exit.x)
		return (1);
	if (layout_cpy[map->exit.y - 1][map->exit.x] != 'W'
		&& layout_cpy[map->exit.y + 1][map->exit.x] != 'W'
		&& layout_cpy[map->exit.y][map->exit.x - 1] != 'W'
		&& layout_cpy[map->exit.y][map->exit.x + 1] != 'W'
		&& layout_cpy[map->exit.y - 1][map->exit.x] != 'G'
		&& layout_cpy[map->exit.y + 1][map->exit.x] != 'G'
		&& layout_cpy[map->exit.y][map->exit.x - 1] != 'G'
		&& layout_cpy[map->exit.y][map->exit.x + 1] != 'G')
		return (1);
	if (map->collect != map->gathered)
		return (1);
	return (0);
}

int	map_check(char *file)
{
	t_map	*map;
	int		valid;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	map->layout = file_to_map(file);
	map->lines = 0;
	while (map->layout[map->lines])
		map->lines++;
	map->gathered = 0;
	map->start.x = 0;
	map->start.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	valid = dimension_check(map) + wall_check(map);
	valid += comp_check(map) + path_check(file, map);
	if (valid == 0)
		return (0);
	else
	{
		ft_printf("Error\n\033[1;31mInvalid Map\033[0m\n");
		return (1);
	}
	return (0);
}
