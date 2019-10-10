/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:35:31 by anorman           #+#    #+#             */
/*   Updated: 2019/05/31 11:07:08 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	int		cnt;

	cnt = 0;
	if (str)
	{
		while (str[cnt])
		{
			ft_putchar(str[cnt]);
			cnt++;
		}
	}
}