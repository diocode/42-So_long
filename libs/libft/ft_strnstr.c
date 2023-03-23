/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:26:59 by digoncal          #+#    #+#             */
/*   Updated: 2023/03/23 10:36:33 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*pbig;
	char		*plittle;

	if (!big && !len)
		return (0);
	pbig = (char *) big;
	plittle = (char *) little;
	i = 0;
	j = 0;
	if (!plittle[j])
		return (pbig);
	while (pbig[i] && i < len)
	{
		while (pbig[i + j] && pbig[i + j] == plittle[j] && (i + j) < len)
			j++;
		if (!plittle[j])
			return (pbig + i);
		i++;
		j = 0;
	}
	return (0);
}
