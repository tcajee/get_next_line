/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:37:13 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/06 03:56:56 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwlen(const char *buffer, char delimiter)
{
	size_t len;

	len = 0;
	if (buffer)
	{
		while (*buffer && *buffer++ != delimiter)
			len++;
	}
	return (len);
}


