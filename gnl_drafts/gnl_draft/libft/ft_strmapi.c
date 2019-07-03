/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:55:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/13 12:39:38 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*cursor;
	char	*new;

	i = 0;
	new = NULL;
	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		if (!new)
			return (NULL);
		cursor = new;
		while (*s)
			*cursor++ = f(i++, *s++);
	}
	return (new);
}
