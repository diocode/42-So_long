/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:54:52 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/09 15:59:03 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	map = (char **)malloc(sizeof(t_map) * lines);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (map);
	i = -1;
	while (i++ < lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

void	fill(char **layout_cpy, t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map.len || y >= data->map.lines)
		return ;
	if (layout_cpy[y][x] == 'W' || layout_cpy[y][x] == 'E'
		|| layout_cpy[y][x] == '1' || layout_cpy[y][x] == 'G')
		return ;
	if (layout_cpy[y][x] == 'C')
	{	
		layout_cpy[y][x] = 'G';
		data->map.gathered++;
	}
	else
		layout_cpy[y][x] = 'W';
	fill(layout_cpy, data, x - 1, y);
	fill(layout_cpy, data, x + 1, y);
	fill(layout_cpy, data, x, y - 1);
	fill(layout_cpy, data, x, y + 1);
}

int	path_check(char *file, t_data *data)
{
	char	**layout_cpy;

	layout_cpy = file_to_map(file);
	fill(layout_cpy, data, data->map.player.x, data->map.player.y);
	if (!data->map.exit.y || !data->map.exit.x)
		return (1);
	if (layout_cpy[data->map.exit.y - 1][data->map.exit.x] != 'W'
		&& layout_cpy[data->map.exit.y + 1][data->map.exit.x] != 'W'
		&& layout_cpy[data->map.exit.y][data->map.exit.x - 1] != 'W'
		&& layout_cpy[data->map.exit.y][data->map.exit.x + 1] != 'W'
		&& layout_cpy[data->map.exit.y - 1][data->map.exit.x] != 'G'
		&& layout_cpy[data->map.exit.y + 1][data->map.exit.x] != 'G'
		&& layout_cpy[data->map.exit.y][data->map.exit.x - 1] != 'G'
		&& layout_cpy[data->map.exit.y][data->map.exit.x + 1] != 'G')
		return (1);
	if (data->map.collect != data->map.gathered)
		return (1);
	return (0);
}

void	map_check(char *file, t_data *data)
{
	data->map.layout = file_to_map(file);
	if (!data->map.layout)
		return ;
	while (data->map.layout[data->map.lines])
		data->map.lines++;
	data->map.valid = dimension_check(data) + wall_check(data);
	data->map.valid += comp_check(data) + path_check(file, data);
	if (data->map.valid == 0)
		return ;
	else
	{
		ft_printf("Error\n\033[1;31mInvalid Map\033[0m\n");
		return ;
	}
	return ;
}
