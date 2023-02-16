/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:54:52 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/16 19:34:25 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(char **map, int lines)
{
	int	y;
	int	x;
	y = 0;
	while (y < lines)
	{
		x = 0;
		if (y == 0 || y == lines - 1)
		{
			while (map[y][x] != '\n')
			{
				if (map[y][x] != '1')
					return (1);
				x++;
			}
			y++;
		}
		else
		{
			if(map[y][0] != '1' || map[y][ft_strlen(map[y]) - 2] != '1')
				return (1);
			y++;
		}
	}
	return (0);
}

int	dimensions_check(char **map)
{
	int	i;
	int	len1;
	int	len2;

	len1 = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len2 = ft_strlen(map[i]);
		if (len1 == len2)
			i++;
		else
			return (1);
	}
	if (len1 - 1 == i)
		return (1);
	return (0);
}

char	**convert_map(char *file)
{
	int		fd;
	int		lines;
	int		i;
	char 	*gnl;
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
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (map);
	map = (char **) malloc(lines * sizeof(char*));
	i = -1;
	while (i++ < lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

int		validate_map(char *file)
{
	int		validate;
	int		lines;
	char	**map;

	map = convert_map(file);
	if (!map)
		return (1);
	lines = 0;
	while(map[lines])
		lines++;
	validate = dimensions_check(map) + wall_check(map, lines);
	if (validate) 
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Invalid number of arguments\n");
		return (1);
	}
	if (!validate_map(av[1]))
		ft_printf("Valid\n");
	else
		ft_printf("Invalid\n");
	return (0);
}
