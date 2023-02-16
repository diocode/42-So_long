/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/14 10:19:37 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*generate_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	
	return (data);
}

int	render(t_data *data)
{
	int	x;
	int	y;

	x = 1200;
	y = 600;
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/banner.xpm", &x, &y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/kid.xpm", &x, &y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	close_win(void)
{
	exit(0);
	return (0);
}

int main(void)
{
	t_data 	*data;
	
	data = generate_data();
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "window");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		return (1);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_HEIGHT, W_WIDTH);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);

	mlx_loop_hook(data->mlx_ptr, render, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, close_win, NULL);
	//render(data);
	mlx_loop(data->mlx_ptr);

	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
