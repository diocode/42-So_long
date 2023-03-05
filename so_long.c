/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/05 16:10:17 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*generate_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->tile.x = TILE;
	data->tile.y = TILE;
	data->map.layout = 0;
	data->map.valid = 0;
	data->map.lines = 0;
	data->map.len = 0;
	data->map.collect = 0;
	data->map.gathered = 0;
	data->map.player.y = 0;
	data->map.player.x = 0;
	data->map.exit.y = 0;
	data->map.exit.x = 0;
	return (data);
}

int	file_check(char *str)
{
	char	*ber;

	str = ft_strrchr(str, '.');
	ber = ".ber";
	return (ft_strncmp(str, ber, 4));
}

int main(int ac, char **av)
{
	t_data	*data;
	
	if (ac != 2 || file_check(av[1]) != 0)
		return (1);
	data = generate_data();
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	map_check(av[1], data);
	if (data->map.valid != 0 || !data->map.layout) 
		return 1;
	render(data);
	return (0);
}

