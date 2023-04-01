/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/04/01 14:30:25 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	handle_keypress(int keysym, t_data *data)
{
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
	if (data->map->layout[data->map->player.y][data->map->player.x] == 'E')
	{
		ft_printf("\033[1;32m🥳 Congrats, you won! 🥳\033[0m\n");
		ft_quit(data);
	}
	return (0);
}

int	render_win(t_data *data)
{
	int	width;
	int	height;

	width = data->map->len * SIZE;
	height = data->map->lines * SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");
	if (!data->win_ptr)
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, height, width);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

int	render(t_data *data)
{
	render_win(data);
	if (!data->win_ptr)
		return (1);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_quit, data);
	render_map(data);
	mlx_loop(data->mlx_ptr);
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
		free(data);
		return (1);
	}
	map_check(av[1], data);
	if (data->map->valid != 0 || !data->map->layout)
	{
		free_game(data);
		return (1);
	}
	render(data);
	free_game(data);
	return (0);
}
