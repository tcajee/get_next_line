/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:10:59 by kseperep          #+#    #+#             */
/*   Updated: 2019/07/05 10:55:49 by kseperep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_newline(char **fd_arr, char **line, int fd, int ret)
{
	char			*temp;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (!ft_strchr(fd_arr[fd], '\0'))
		i++;
	if (fd_arr[fd][i] == '\n')
	{
		len = i;
		*line = ft_strsub(fd_arr[fd], 0, len);
		temp = ft_strdup(fd_arr[fd] + len + 1);
		free(fd_arr[fd]);
		fd_arr[fd] = temp;
		/* if (fd_arr[fd][0] == '\0') */
			/* ft_strdel(&fd_arr[fd]); */
	}
	else if (fd_arr[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(fd_arr[fd]);
		ft_strdel(&fd_arr[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_arr[1025];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	if (fd_arr[fd] == NULL)
		fd_arr[fd] = ft_strnew(0);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ret == 0)
			return (0);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		temp = ft_strjoin(fd_arr[fd], buffer);
		free(fd_arr[fd]);
		fd_arr[fd] = temp;
		if (ft_strchr(fd_arr[fd], '\n'))
			break ;
	}
	return (ft_newline(&fd_arr[fd], line, fd, ret));
}
