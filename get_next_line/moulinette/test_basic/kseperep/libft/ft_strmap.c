/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:12:04 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/25 14:57:20 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		dst = ft_strnew(len);
		if (dst == NULL)
			return (NULL);
		while (i < len)
		{
			dst[i] = f(s[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
