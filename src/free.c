/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:28:47 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 15:46:33 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	if (!map->layout)
		return ;
	i = 0;
	while (map->layout[i])
		free(map->layout[i++]);
	free(map->layout);
	free(map);
}

void	free_tiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TILES)
		mlx_destroy_image(data->mlx_ptr, data->tiles[i++]);
	free(data->tiles);
}

int	free_game(t_data *data)
{
	if (!data)
		return (0);
	if (data->tiles)
		free_tiles(data);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->map)
		free_map(data->map);
	free(data->mlx_ptr);
	return (0);
}
