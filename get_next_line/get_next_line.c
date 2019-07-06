/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:10:59 by kseperep          #+#    #+#             */
/*   Updated: 2019/07/06 04:23:03 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				ft_newline(char **fd_arr, char **line, int fd, int ret)
{
	char		*temp;
	int			len;

	if (ft_strchr(fd_arr[fd], '\n'))
	{
		temp = fd_arr[fd];
		printf("%s", fd_arr[fd]);
		printf("if\n");
		len = ft_strwlen(fd_arr[fd], '\n');
		*line = ft_strsub(fd_arr[fd], 0, len);
		ft_strdel(&fd_arr[fd]);
		printf("fd_arr[fd] = %s\n", fd_arr[fd]);
		fd_arr[fd] = ft_strdup(temp + len + 1);
	}
	else if (ret < BUFF_SIZE)
	{
		*line = ft_strdup(fd_arr[fd]);
		ft_strdel(&fd_arr[fd]);
		return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_arr[1025];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	printf("here\n");
	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	if (fd_arr[fd] == NULL)
		fd_arr[fd] = ft_strnew(0);
	while (!(ft_strchr(fd_arr[fd], '\n')))
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == 0)
			return (0);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		temp = ft_strjoin(fd_arr[fd], buffer);
		ft_strdel(&fd_arr[fd]);
		fd_arr[fd] = temp;
		printf("while  %s\n", fd_arr[fd]);
	}
	return (ft_newline(fd_arr, line, ret));
}
