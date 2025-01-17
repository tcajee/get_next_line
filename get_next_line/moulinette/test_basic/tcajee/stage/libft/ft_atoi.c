/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:09:55 by lnagy             #+#    #+#             */
/*   Updated: 2015/12/31 00:16:12 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	tmp;
	int	i;
	int	sig;

	sig = 1;
	i = 0;
	tmp = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\n' || s[i] == '\f' || s[i] == '\v')
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		++i;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		tmp = tmp * 10;
		tmp = tmp + s[i] - '0';
		++i;
	}
	return (tmp * sig);
}
