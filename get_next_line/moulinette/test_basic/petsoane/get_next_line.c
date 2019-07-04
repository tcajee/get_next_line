/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 08:07:15 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/08 13:04:21 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_isline(char *s)
{
	while (*s)
	{
		if (*(s + 1) == '\0' &&  *s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	char		*out;
	static char	*inc_buff;

	if (fd < 0 || read(fd, &out, 0) == -1)
		return (-1);
	i = 0;
	inc_buff = NULL;
	if (!(out =(char *) malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, &out[i], 1)) > 0 && out[i] !='\n' && i < BUFF_SIZE)
		i++;
	out[i + 1] = '\0';
	if (!ft_isline(out) && i == BUFF_SIZE)
	{
		get_next_line(fd, &inc_buff);
		*line = ft_strjoin(out, inc_buff);
	}else
	{
		out[i] = '\0';
		*line = out;
	}
	if (ret != 0)
		return (ret);
	return (0);
}
