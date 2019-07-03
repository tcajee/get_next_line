/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:58:02 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/13 14:44:27 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		minsize;
	const char	*cursor;

	minsize = ft_strlen(needle);
	cursor = haystack;
	if (minsize == 0)
		return ((char *)haystack);
	while (*cursor && (cursor + minsize) <= (haystack + len))
	{
		if (*cursor == *needle && \
				ft_strncmp(cursor, needle, minsize) == 0)
			return ((char *)cursor);
		cursor++;
	}
	return (NULL);
}
