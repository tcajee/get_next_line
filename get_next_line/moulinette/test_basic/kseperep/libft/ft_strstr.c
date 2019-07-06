/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:22:04 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/25 11:03:31 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		pos = 0;
		while (needle[pos] == haystack[i + pos])
		{
			if (needle[pos + 1] == '\0')
				return ((char *)haystack + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
