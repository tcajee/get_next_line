/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:10:59 by kseperep          #+#    #+#             */
/*   Updated: 2019/07/06 04:30:04 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_newline(char **str, char **line, int fd, int ret)
{
	char			*temp;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		len = i;
		*line = ft_strsub(str[fd], 0, len);
		temp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_arr[1025];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (fd_arr[fd] == NULL)
			fd_arr[fd] = ft_strnew(1);
		temp = ft_strjoin(fd_arr[fd], buffer);
		free(fd_arr[fd]);
		fd_arr[fd] = temp;
		if (ft_strchr(fd_arr[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (fd_arr[fd] == NULL || fd_arr[fd][0] == '\0'))
		return (0);
	return (ft_newline(fd_arr, line, fd, ret));
}
