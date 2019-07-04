/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:19:04 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/28 16:23:26 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;


	i = 0;
		return ((char *)h);
	while (*h)
	{
		i = 0;
		while (*(h + i) == n[i])
		{
			if (n[i + 1] == '\0')
				return ((char *)h);
			i++;
		}
		h++;
	}
	return (NULL);

}
