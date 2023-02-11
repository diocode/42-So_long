/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:19:01 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/08 16:00:56 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
/*render rectangle*/
int render_rect(t_data *data)
{
	int x, y;
	
	if (!data->win_ptr)
		return (1);
	y = W_WIDTH - 100;
	while (y < (W_WIDTH - 100) + 100)
	{
		x = W_HEIGHT -100;
		while (x < (W_HEIGHT - 100) + 100)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x++, y, RED_PIXEL);
		++y;
	}
	return (0);
}

/* if window has been destroyed, we don't want to put the pixel ! */
int	render(t_data *data)
{
	render_rect(data);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		ft_printf("\033[1;32mKeypress: \033[0mESC\n");
	}
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT, "window");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
