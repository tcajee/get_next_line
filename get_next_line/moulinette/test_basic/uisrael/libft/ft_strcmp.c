/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:14:54 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/21 20:07:10 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
		return (-1);
	else if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
		return (1);
	else
		return (0);
}
