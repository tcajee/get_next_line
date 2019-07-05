/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:12:38 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/07 12:11:28 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	counter;
	size_t	len;

	if (!s)
	{
		return ;
	}
	len = ft_strlen(s);
	counter = 0;
	while (counter < len)
	{
		s[counter++] = '\0';
	}
}
