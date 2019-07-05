/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:49:35 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/18 10:00:43 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			counter;
	char			*holddst;
	char			*holdsrc;

	holdsrc = (char*)src;
	holddst = (char*)dst;
	counter = 0;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (counter < n)
	{
		holddst[counter] = holdsrc[counter];
		counter++;
	}
	return (dst);
}
