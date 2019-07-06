/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:15:21 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/07 08:37:54 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lst_occ;

	lst_occ = 0;
	while (*s)
	{
		if (*s == c)
			lst_occ = (char*)s;
		++s;
	}
	if (lst_occ)
		return (lst_occ);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
