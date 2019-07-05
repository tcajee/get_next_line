/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:17:42 by dlinde            #+#    #+#             */
/*   Updated: 2019/07/04 12:40:53 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int neg;
	int nb;
	int n;

	neg = 1;
	nb = 0;
	n = 0;
	if (!str)
		return (0);
	while (str[n] == '\n' || str[n] == '\t' || str[n] == '\v' ||
			str[n] == ' ' || str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-')
		neg = -1;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while (str[n] >= '0' && str[n] <= '9')
	{
		nb = nb * 10 + (str[n] - '0');
		n++;
	}
	return (nb * neg);
}
