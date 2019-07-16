/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:00:39 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/16 08:34:14 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		getline(char **stat, char **line)
{
	char *tmp;

	if (ft_strchr(*stat, '\n') != NULL)
	{
		*(ft_strchr(*stat, '\n')) = '\0';
		*line = ft_strdup(*stat);
		tmp = ft_strdup(ft_strchr(*stat, '\0') + 1);
		free(*stat);
		*stat = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*stat);
		ft_memdel((void **)stat);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			br;
	char		buffer[BUFF_SIZE + 1];
	static char	*stat[1025];
	char		*tmp;

	if (read(fd, NULL, 0) == -1 || !line)
		return (-1);
	if (!(stat[fd]))
		stat[fd] = ft_strnew(0);
	while (ft_strchr(stat[fd], '\n') == NULL)
	{
		if ((br = read(fd, buffer, BUFF_SIZE)) == 0)
			return (0);
		if (br < 0)
			return (-1);
		buffer[br] = '\0';
		tmp = ft_strjoin(stat[fd], buffer);
		free(stat[fd]);
		stat[fd] = ft_strdup(tmp);
		free(tmp);
	}
	return (getline(&stat[fd], line));
}
