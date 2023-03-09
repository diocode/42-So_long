/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:02:51 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/09 15:59:10 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	comp_check_check_check(t_data *data, int start_exit)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	if (start_exit != 2)
		return (1);
	if (data->map.collect < 1)
		return (1);
	str = "01CEP";
	y = -1;
	while (++y < data->map.lines)
	{
		x = -1;
		while (data->map.layout[y][++x] != '\n' && data->map.layout[y][x] != '\0')
		{
			i = -1;
			while (str[++i])
				if (data->map.layout[y][x] == str[i])
					break ;
			if (i == 5)
				return (1);
		}
	}
	return (0);
}

int	comp_check_check(t_data *data, int x, int y)
{
	int	start_exit;

	start_exit = 0;
	if (data->map.layout[y][x] == 'C')
		data->map.collect++;
	if (data->map.layout[y][x] == 'P')
	{
		data->map.player.x = x;
		data->map.player.y = y;
		start_exit++;
	}
	if (data->map.layout[y][x] == 'E')
	{
		data->map.exit.x = x;
		data->map.exit.y = y;
		start_exit++;
	}
	return (start_exit);
}

int	comp_check(t_data *data)
{
	int	start_exit;
	int	x;
	int	y;

	data->map.collect = 0;
	start_exit = 0;
	y = -1;
	while (data->map.layout[++y])
	{
		x = -1;
		while (data->map.layout[y][++x])
			start_exit += comp_check_check(data, x, y);
	}
	return (comp_check_check_check(data, start_exit));
}

int	wall_check(t_data *data)
{	
	int	y;
	int	x;

	y = 0;
	while (y < data->map.lines)
	{
		x = -1;
		if (y == 0 || y == data->map.lines - 1)
		{
			while (data->map.layout[y][++x] != '\n' && data->map.layout[y][x] != '\0')
			{
				if (data->map.layout[y][x] != '1')
					return (1);
			}
			y++;
		}
		else
		{
			if (data->map.layout[y][0] != '1'
				|| data->map.layout[y][ft_strlen(data->map.layout[y]) - 2] != '1')
				return (1);
			y++;
		}
	}
	return (0);
}

int	dimension_check(t_data *data)
{
	int	len;
	int	x;

	data->map.len = strlen_solong(data->map.layout[0]);
	len = 0;
	x = 1;
	while (data->map.layout[x])
	{
		len = strlen_solong(data->map.layout[x]);
		if (len == data->map.len)
			x++;
		else
			return (1);
	}
	return (0);
}
