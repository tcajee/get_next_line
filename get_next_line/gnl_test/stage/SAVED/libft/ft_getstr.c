/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 12:07:21 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/04 13:22:11 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getstr(void)
{
	char	*s;
	size_t	i;

	s = ft_strnew(0);
	i = 0;
	while ((s[i] = ft_getchar()) != '\n')
		i++;
	s[i] = '\0';
	return (s);
}