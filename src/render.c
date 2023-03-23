/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:41 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 15:46:08 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_game(data);
	if (keysym == XK_Up || keysym == XK_w)
		move_up(data);
	if (keysym == XK_Down || keysym == XK_s)
		move_down(data);
	if (keysym == XK_Right || keysym == XK_d)
		move_right(data);
	if (keysym == XK_Left || keysym == XK_a)
		move_left(data);
	if (data->map->layout[data->map->player.y][data->map->player.x] == 'E')
	{
		ft_printf("\033[1;32m🥳 Congrats, you won! 🥳\033[0m\n");
		free_game(data);
	}
	return (0);
}

int	render(t_data *data)
{
	render_win(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&free_game, data);
	render_map(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
