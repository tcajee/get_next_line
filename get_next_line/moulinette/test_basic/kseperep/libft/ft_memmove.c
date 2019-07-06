/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <kseperep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:52:07 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/19 15:10:07 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (n <= 0)
		return (dst);
	if (str2 < str1)
	{
		while (n > 0)
		{
			str1[n - 1] = str2[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(str1, str2, n);
	}
	return (dst);
}
