/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <kseperep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:39:59 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/18 13:45:05 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*cpsrc;
	unsigned char		*todst;
	size_t				i;

	cpsrc = (unsigned char*)src;
	todst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		todst[i] = cpsrc[i];
		if (cpsrc[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
