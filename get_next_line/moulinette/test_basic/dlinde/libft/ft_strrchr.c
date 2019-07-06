/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:57:02 by dlinde            #+#    #+#             */
/*   Updated: 2019/05/23 12:22:32 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = 0;
	while (s[n] != '\0')
		n++;
	while (n >= 0)
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
		n--;
	}
	return (0);
}