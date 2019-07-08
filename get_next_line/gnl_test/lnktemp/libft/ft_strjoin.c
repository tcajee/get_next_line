/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:31:04 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 14:03:33 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	h;
	size_t	i;
	size_t	j;
	char	*n;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(n = ft_strnew(++i)))
			return (NULL);
		h = ft_strlen(s1);
		i = -1;
		while (++i < h)
			n[i] = s1[i];
		j = 0;
		h = ft_strlen(s2);
		while (j < h)
			n[i++] = s2[j++];
		n[i] = '\0';
		return (n);
	}
	return (NULL);
}
