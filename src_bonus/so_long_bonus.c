/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/17 17:12:19 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	generate_img(t_data *data)
{
	data->map.tiles.wall_u_l = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u_l.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_u_r = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u_r.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_u = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_u.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_r = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_r.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_m = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_m.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_l = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_l.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_d_l = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d_l.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_d_r = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d_r.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.wall_d = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall_d.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_4.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collect_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.player_idle_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.player_idle_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_idle_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_player_idle_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_idle_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_player_idle_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_idle_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.player_walk_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_walk_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.player_walk_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player_walk_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_player_walk_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_walk_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_player_walk_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_player_walk_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.collect_idle_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collect_idle_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.collect_idle_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collect_idle_3.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.start_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.start_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.start_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_3.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.start_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/start_4.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_3.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_4.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_5.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_6 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_6.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.exit_7 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_7.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.atk_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.atk_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.atk_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_3.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.atk_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_4.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.atk_5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/atk_5.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_atk_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_atk_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_atk_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_3.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_atk_4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_4.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_atk_5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_atk_5.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.enemy_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.enemy_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.enemy_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy_3.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_enemy_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_enemy_1.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_enemy_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_enemy_2.xpm", &data->tile.x, &data->tile.y);
	data->map.tiles.r_enemy_3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/r_enemy_3.xpm", &data->tile.x, &data->tile.y);
}

t_data	*generate_data(void)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (data);
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->tile.y = TILE;
	data->tile.x = TILE;
	data->moves = 0;
	data->loop = 0;
	data->idle = 0;
	data->finish = 0;
	data->direc = 'r';
	data->atk = 0;
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
	data->map.enemies = 0;
	data->map.enemy_x = 0;
	data->map.enemy_y = 0;

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
	generate_img(data);
	map_check(av[1], data);
	if (data->map.valid != 0 || !data->map.layout)
		return 1;
	render(data);
	return (0);
}