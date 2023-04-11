/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:48:57 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/06 10:49:12 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_img(t_data *data)
{
	data->img.mlx_img = NULL;
	data->img.addr = NULL;
	data->img.bpp = 0;
	data->img.endian = 0;
	data->img.line_len = 0;
}

int	init_nbr(t_data *data)
{
	data->nbr = malloc(10 * sizeof(char *));
	if (!data->nbr)
		return (1);
	data->nbr[0] = "./textures/0.xpm";
	data->nbr[1] = "./textures/1.xpm";
	data->nbr[2] = "./textures/2.xpm";
	data->nbr[3] = "./textures/3.xpm";
	data->nbr[4] = "./textures/4.xpm";
	data->nbr[5] = "./textures/5.xpm";
	data->nbr[6] = "./textures/6.xpm";
	data->nbr[7] = "./textures/7.xpm";
	data->nbr[8] = "./textures/8.xpm";
	data->nbr[9] = "./textures/9.xpm";
	return (0);
}

void	init_null(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->moves = 0;
	data->loop = 0;
	data->idle = 0;
	data->finish = 0;
	data->direc = 'r';
	data->atk = 0;
	data->map->layout = NULL;
	data->map->valid = 0;
	data->map->lines = 0;
	data->map->len = 0;
	data->map->collect = 0;
	data->map->gathered = 0;
	data->map->player.y = 0;
	data->map->player.x = 0;
	data->map->exit.y = 0;
	data->map->exit.x = 0;
	data->map->enemies = 0;
	data->map->enemy_x = NULL;
	data->map->enemy_y = NULL;
}

t_data	*init_data(void)
{
	t_data	*data;

	srand(time(NULL));
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (NULL);
	data->tile.y = SIZE;
	data->tile.x = SIZE;
	init_null(data);
	init_img(data);
	if (init_nbr(data))
		return (NULL);
	return (data);
}

t_data	*init(void)
{
	t_data	*data;

	data = init_data();
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (NULL);
	return (data);
}
