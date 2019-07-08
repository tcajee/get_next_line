/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:31:12 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/21 07:59:33 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	len;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	len = dstlen;
	if (dstlen > dstsize)
		len = dstsize;
	len = len + srclen;
	while ((src[i] != '\0') && (i + dstlen < dstsize - 1) && (dstsize > 0))
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (len);
}
