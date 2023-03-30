/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:41 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/30 00:28:23 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	int	enemies;
	int	stuck;
	
	if (keysym == XK_Escape)
		exit(0);
	if (keysym == XK_Up || keysym == XK_w)
		move_up(data);
	if (keysym == XK_Down || keysym == XK_s)
		move_down(data);
	if (keysym == XK_Right || keysym == XK_d)
		move_right(data);
	if (keysym == XK_Left || keysym == XK_a)
		move_left(data);
	if (data->map->gathered == 0 && data->finish == 0)
	{
		exit_anim(data);
		data->finish = 1;
	}
	if (data->map->layout[data->map->player.y][data->map->player.x] == 'E')
	{
		ft_printf("\033[1;32m🥳 Congrats, you won! 🥳\033[0m\n");
		ft_quit(data);
	}
	enemies = data->map->enemies;
	if (data->moves != 0)
	{
		while (--enemies >= 0)
		{
			stuck = data->map->enemy_x[enemies] + data->map->enemy_y[enemies];
			move_enemy(data, enemies);
			if (stuck == data->map->enemy_x[enemies] + data->map->enemy_y[enemies])
				enemies++;
		}
	}
	return (0);
}

int	render(t_data *data)
{
	render_win(data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &ft_quit, NULL);
	mlx_loop_hook(data->mlx_ptr, &player_idle, data);
	render_map(data);
	render_enemies(data);
	start_anim(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}
