/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 10:19:03 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new_line(t_files *files, int fd, char **file)
{
	int		bytes;

	if (!file[fd])
		file[fd] = ft_strnew(0);
	while (ft_strchr(file[fd], '\n') == NULL)
	{
		if ((bytes = read(fd, files->buffer, BUFF_SIZE)) == 0)
			break ;
		if (bytes < 0)
			return (-1);
		files->stage = ft_strjoin(file[fd],\
				ft_memset(files->buffer + bytes, '\0', 1) - bytes);
		ft_strdel(&file[fd]);
		file[fd] = ft_strdup(files->stage);
		ft_strdel(&files->stage);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_files files;

	if (fd < 0 || !line || find_new_line(&files, fd, files.file) < 0)
		return (-1);
	if (ft_strchr(files.file[fd], '\n') != NULL)
	{
		files.stage = ft_strdup(files.file[fd]);
		*line = ft_strdup(ft_memset(ft_strchr(\
						files.stage, '\n'), '\0', 1) - ft_strlen(files.stage));
		ft_strdel(&files.file[fd]);
		files.file[fd] = ft_strdup(ft_strchr(files.stage, '\0') + 1);
		ft_strdel(&files.stage);
	}
	else if ((*line = ft_strdup(files.file[fd])) && files.file[fd][0])
		ft_strdel(&files.file[fd]);
	else
	{
		ft_strdel(&files.file[fd]);
		return (0);
	}
	return (1);
}
