/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:13:24 by kseperep          #+#    #+#             */
/*   Updated: 2019/06/25 09:38:31 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strlennbr(int n)
{
	int				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	long			tmp;
	char			*s;
	unsigned int	len;

	tmp = (long)n;
	len = ft_strlennbr(tmp) + (n < 0);
	if (n < 0)
		tmp = (tmp * -1);
	s = NULL;
	s = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	while (len > 0)
	{
		s[len - 1] = (tmp % 10) + '0';
		len--;
		tmp = tmp / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
