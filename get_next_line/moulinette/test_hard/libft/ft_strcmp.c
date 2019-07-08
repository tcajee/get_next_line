/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:21:20 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/21 09:42:38 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_memcmp(s1, s2, (ft_strlen(s1) + 1)) > 0)
		return (1);
	else if (ft_memcmp(s1, s2, (ft_strlen(s1) + 1)) < 0)
		return (-1);
	else
		return (0);
}
