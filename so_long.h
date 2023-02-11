/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:27 by digoncal          #+#    #+#             */
/*   Updated: 2023/02/08 11:50:50 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*---------- LIBRARIES ----------*/

#include "src/minilibx/mlx.h"
#include "src/libft/libft.h"

#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdint.h>

/*---------- STRUCTURES ----------*/

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

/*---------- VARIABLES ----------*/

#define W_WIDTH 1200
#define W_HEIGHT 600
#define RED_PIXEL 0xFF0000


/*---------- FUNCTIONS ----------*/

#endif
