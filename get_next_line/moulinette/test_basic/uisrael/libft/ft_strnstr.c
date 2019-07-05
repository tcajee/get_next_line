/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:58:43 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/08 16:37:35 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(to_find);
	if (!*to_find && str == to_find)
		return ((char *)str);
	while (str[i] != '\0' && len + i <= n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] && to_find[j])
			j++;
		if (!(to_find[j]))
			return ((char *)str + i);
		i++;
	}
	return (0);
}
