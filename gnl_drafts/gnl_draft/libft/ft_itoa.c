/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:38:25 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/13 15:52:43 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*head;
	char	*string;
	int		x;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
		x = n * -1;
	else
		x = n;
	string = ft_strnew(12);
	if (!string)
		return (NULL);
	head = string;
	while (x > 0)
	{
		*string++ = (x % 10) + 48;
		x /= 10;
	}
	if (n < 0)
		*string = '-';
	head = ft_strcpy(ft_strnew(ft_strlen(head)), ft_strrev(head));
	return (head);
}
