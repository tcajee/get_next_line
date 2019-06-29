/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/29 11:49:11 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	copy_new_line(t_files *files, int fd)
{
	FT_(!(files->stage = ft_strdup(files->file[fd])), -1);
//	ft_strdel(&files->line);
	ft_memset(ft_strchr(files->stage, '\n'), '\0', 1);
	FT_(!(files->line = ft_strdup(files->stage)), -1);
	ft_strdel(&files->file[fd]);
	FT_(!(files->file[fd] = ft_strdup(ft_strchr(files->stage, '\0') + 1)), -1);
	ft_strdel(&files->stage);
	return (1);
}

static int	find_new_line(t_files *files, int fd)
{
	int		bytes;

	if (!files->file[fd])
		files->file[fd] = ft_strnew(0);
	while (ft_strchr(files->file[fd], '\n') == NULL)
	{
		FT_(!(files->buffer = ft_strnew(BUFF_SIZE)), -1);
		FT_((bytes = read(fd, files->buffer, BUFF_SIZE)) == 0, 0);
		if (bytes < 0)
		{
			ft_strdel(&files->buffer);
			return (-1);
		}
		FT_(!(files->stage = ft_strjoin(files->file[fd], files->buffer)), -1);
		ft_strdel(&files->file[fd]);
		ft_strdel(&files->buffer);
		FT_(!(files->file[fd] = ft_strdup(files->stage)), -1);
		ft_strdel(&files->stage);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_files files;

	FT_((fd < 0 || !line || read(fd, NULL, 0) == -1), -1);
	FT_(find_new_line(&files, fd) < 0, -1);
	if (ft_strchr(files.file[fd], '\n') != NULL)
	{
		FT_(copy_new_line(&files, fd) < 0, -1);
		FT_(!(*line = ft_strdup(files.line)), -1);
		ft_strdel(&files.line);
	}
	else if (ft_strlen(files.file[fd]) > 0)
	{
		FT_(!(*line = ft_strdup(files.file[fd])), -1);
		ft_strdel(&files.file[fd]);
	}
	else
		return (0);
	return (1);
}
