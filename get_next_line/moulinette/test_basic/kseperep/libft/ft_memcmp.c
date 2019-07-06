/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:58:10 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/10 16:58:35 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = str1;
	p2 = str2;
	while (n--)
	{
		if (*p1 != *p2)
			return ((unsigned int)*p1 - (unsigned int)*p2);
		else
		{
			p1++;
			p2++;
		}
	}
	return (0);
}
