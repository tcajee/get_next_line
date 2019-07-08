/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:21:20 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/21 09:51:11 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	len = n;
	if (ft_strlen(s1) < n)
		len = ft_strlen(s1) + 1;
	if (ft_memcmp(s1, s2, len) > 0)
		return (1);
	else if (ft_memcmp(s1, s2, len) < 0)
		return (-1);
	else
		return (0);
}
