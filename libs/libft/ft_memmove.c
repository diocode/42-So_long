/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:50:43 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 10:35:24 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned const char	*csrc;

	cdest = dest;
	csrc = src;
	if (!cdest && !csrc)
		return (NULL);
	if (cdest > csrc)
	{
		while (n-- > 0)
			cdest[n] = csrc[n];
	}
	else
	{
		while (n-- > 0)
			*cdest++ = *csrc++;
	}
	return (dest);
}
