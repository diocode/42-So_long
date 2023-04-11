/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/06 10:56:49 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	int	moves;

	moves = data->moves;
	if (keysym == XK_Escape)
		ft_quit(data);
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
	enemy_pos(data, moves);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || file_check(av[1]) != 0)
		return (1);
	data = init();
	if (!data)
	{
		free_game(data);
		return (1);
	}
	map_check(av[1], data);
	if (data->map->valid != 0 || !data->map->layout)
	{
		free_game(data);
		return (1);
	}
	if (init_enemy(data))
	{
		free_game(data);
		return (1);
	}
	render(data);
	free_game(data);
	return (0);
}
