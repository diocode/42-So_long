/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:02:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/05 11:34:28 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	comp3_check(t_data *data, int start_exit)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	if (start_exit != 2 || data->map->collect < 1)
		return (1);
	str = "01CEP";
	y = -1;
	while (++y < data->map->lines)
	{
		x = -1;
		while (data->map->layout[y][++x] != '\n'
			&& data->map->layout[y][x] != '\0')
		{
			i = -1;
			while (str[++i])
				if (data->map->layout[y][x] == str[i])
					break ;
			if (i == 5)
				return (1);
		}
	}
	return (0);
}

int	comp2_check(t_data *data, int x, int y)
{
	int	start_exit;

	start_exit = 0;
	if (data->map->layout[y][x] == 'C')
		data->map->collect++;
	if (data->map->layout[y][x] == 'P')
	{
		data->map->player.x = x;
		data->map->player.y = y;
		start_exit++;
	}
	if (data->map->layout[y][x] == 'E')
	{
		data->map->exit.x = x;
		data->map->exit.y = y;
		start_exit++;
	}
	return (start_exit);
}

int	map_lines(char *file)
{
	char	*gnl;
	int		lines;
	int		fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = 0;
	gnl = get_next_line(fd);
	while (gnl && lines++ >= 0)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
	return (lines);
}

char	**file_to_map(char *file)
{
	int		lines;
	int		fd;
	int		i;
	char	**map;

	lines = map_lines(file);
	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = -1;
	while (++i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i] || map[i][0] == '\r')
		{
			free_array(map);
			close(fd);
			return (NULL);
		}
	}
	close(fd);
	return (map);
}

void	fill(char **layout_cpy, t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map->len || y >= data->map->lines)
		return ;
	if (layout_cpy[y][x] == 'W' || layout_cpy[y][x] == '1'
		|| layout_cpy[y][x] == 'G')
		return ;
	if (layout_cpy[y][x] == 'C')
	{	
		layout_cpy[y][x] = 'G';
		data->map->gathered++;
	}
	if (layout_cpy[y][x] == 'E')
	{
		layout_cpy[y][x] = 'W';
		return ;
	}
	else
		layout_cpy[y][x] = 'W';
	fill(layout_cpy, data, x - 1, y);
	fill(layout_cpy, data, x + 1, y);
	fill(layout_cpy, data, x, y - 1);
	fill(layout_cpy, data, x, y + 1);
}