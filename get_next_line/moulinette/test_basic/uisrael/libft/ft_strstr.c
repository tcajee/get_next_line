/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:44:59 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/07 14:58:10 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	cneed;
	size_t	chay;

	chay = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[chay] != '\0')
	{
		cneed = 0;
		while (haystack[chay + cneed] == needle[cneed])
		{
			if (needle[cneed + 1] == '\0')
				return ((char *)haystack + chay);
			cneed++;
		}
		chay++;
	}
	return (NULL);
}
