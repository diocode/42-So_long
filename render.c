/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:41 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/03 13:37:28 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void)
{
	exit(0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{	
	if (keysym == XK_Escape)
		exit(0);
	if (keysym == XK_Up || keysym == XK_w)
	{
		data->map.layout[data->map.player.y][data->map.player.x] = '0';
		data->map.player.y -= 1;
		data->map.layout[data->map.player.y][data->map.player.x] = 'P';
		render_map(data);
	}	
	/*if (keysym == XK_Down || keysym == XK_s)
	if (keysym == XK_Right || keysym == XK_d)
	if (keysym == XK_Left || keysym == XK_a)*/
	return (0);
}

int	render(t_data *data)
{
	render_win(data);
//	mlx_loop_hook(data->mlx_ptr, rendering, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, close_win, NULL);
	render_map(data);
	mlx_loop(data->mlx_ptr);

	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}
