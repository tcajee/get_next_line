/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:10:23 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/03 15:46:20 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	counter;

	counter = 0;
	while (src[counter] != '\0' && counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	ft_memset(dst + counter, '\0', len - counter);
	return (dst);
}
