/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:42:33 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/28 20:36:33 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_img1(t_data *data)
{
	data->tiles[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &data->tile.x, &data->tile.y);
	data->tiles[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u_l.xpm", &data->tile.x, &data->tile.y);
	data->tiles[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u_r.xpm", &data->tile.x, &data->tile.y);
	data->tiles[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u.xpm", &data->tile.x, &data->tile.y);
	data->tiles[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_r.xpm", &data->tile.x, &data->tile.y);
	data->tiles[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_m.xpm", &data->tile.x, &data->tile.y);
	data->tiles[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_l.xpm", &data->tile.x, &data->tile.y);
	data->tiles[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d_l.xpm", &data->tile.x, &data->tile.y);
	data->tiles[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d_r.xpm", &data->tile.x, &data->tile.y);
	data->tiles[9] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d.xpm", &data->tile.x, &data->tile.y);
}

void	init_img2(t_data *data)
{
	data->tiles[10] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[11] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[12] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_3.xpm", &data->tile.x, &data->tile.y);
	data->tiles[13] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_4.xpm", &data->tile.x, &data->tile.y);
	data->tiles[14] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[15] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[16] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_3.xpm", &data->tile.x, &data->tile.y);
	data->tiles[17] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_4.xpm", &data->tile.x, &data->tile.y);
	data->tiles[18] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collect_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[19] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collect_idle_2.xpm", &data->tile.x, &data->tile.y);
}

void	init_img3(t_data *data)
{
	data->tiles[20] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[21] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_idle_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[22] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[23] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_idle_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[24] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_walk_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[25] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_walk_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[26] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_walk_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[27] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_walk_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[28] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_d_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[29] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_d_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[30] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_d_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[31] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_d_2.xpm", &data->tile.x, &data->tile.y);
}

void	init_img4(t_data *data)
{
	data->tiles[32] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[33] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[34] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_3.xpm", &data->tile.x, &data->tile.y);
	data->tiles[35] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[36] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[37] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_3.xpm", &data->tile.x, &data->tile.y);
	data->tiles[38] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[39] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy_2.xpm", &data->tile.x, &data->tile.y);
	data->tiles[40] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_enemy_1.xpm", &data->tile.x, &data->tile.y);
	data->tiles[41] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_enemy_2.xpm", &data->tile.x, &data->tile.y);
}
