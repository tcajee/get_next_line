/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <kseperep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:52:37 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/18 14:46:11 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)dest;
	str2 = (char *)src;
	i = 0;
	while (i < n)
	{
		if (n == 0 || str1 == str2)
			return (dest);
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
