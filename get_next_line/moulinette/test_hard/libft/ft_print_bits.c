/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 07:21:01 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/20 09:08:37 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int		i;
	char	tab[8];
	char	c;

	i = 0;
	while (i < 8)
	{
		tab[i] = octet % 2;
		octet = octet / 2;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = tab[i] + 48;
		ft_putchar(c);
		i--;
	}
}
