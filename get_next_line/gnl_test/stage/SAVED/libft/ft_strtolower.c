/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:06:47 by marvin            #+#    #+#             */
/*   Updated: 2019/06/13 20:06:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtolower(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        str[i] = ft_tolower(str[i]);
        i++;
    }
    return(str);
}