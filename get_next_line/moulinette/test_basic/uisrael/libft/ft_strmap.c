/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisrael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:07:53 by uisrael           #+#    #+#             */
/*   Updated: 2019/06/21 21:10:40 by uisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	size_t	counter;

	counter = 0;
	if (!s)
	{
		return (NULL);
	}
	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!temp)
	{
		return (NULL);
	}
	while (s[counter] != '\0')
	{
		temp[counter] = f(s[counter]);
		counter++;
	}
	temp[counter] = '\0';
	return (temp);
}
