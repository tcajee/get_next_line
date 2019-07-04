/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:58:31 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:58:35 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dest[j] && j < n)
		j++;
	i = 0;
	while ((src[i]) && ((j + i + 1) < n))
	{
		dest[j + i] = src[i];
		++i;
	}
	if (j != n)
		dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
