/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchewa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:14:12 by tchewa            #+#    #+#             */
/*   Updated: 2019/06/05 11:12:23 by tchewa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bytes;
	unsigned char	chars;

	bytes = (unsigned char*)b;
	chars = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		bytes[i] = chars;
		i++;
	}
	return (bytes);
}
