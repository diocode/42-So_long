/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/28 22:33:23 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

int main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || file_check(av[1]) != 0)
		return (1);
	data = init();
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	map_check(av[1], data);
	if (data->map->valid != 0 || !data->map->layout)
		return 1;
	init_enemy(data);
	render(data);
	return (0);
}