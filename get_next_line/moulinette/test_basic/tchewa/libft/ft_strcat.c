/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchewa <tchewa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:57:55 by tchewa            #+#    #+#             */
/*   Updated: 2019/06/13 16:45:39 by tchewa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = (char)src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
