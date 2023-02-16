/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/15 10:52:03 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*---------- LIBRARIES ----------*/

#include "libs/minilibx/mlx.h"
#include "libs/libft/libft.h"

#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include <fcntl.h>

/*---------- STRUCTURES ----------*/

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

/*---------- VARIABLES ----------*/

#define W_WIDTH 1200
#define W_HEIGHT 600

/*---------- FUNCTIONS ----------*/

#endif
