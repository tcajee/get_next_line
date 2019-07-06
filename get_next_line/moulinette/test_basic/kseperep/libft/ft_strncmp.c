/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:18:56 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/25 15:00:08 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n - 1))
			i++;
		if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
			return (1);
		if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
			return (-1);
		else
			return (0);
	}
	return (0);
}
