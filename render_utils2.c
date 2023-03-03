/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:19 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/03 12:18:46 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data)
{
	int	w;
	int	h;

	w = TILE;
	h = TILE;
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/player.xpm", &w, &h);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, data->map.player.x * TILE, data->map.player.y * TILE);
}
