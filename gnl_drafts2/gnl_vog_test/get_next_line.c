/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/28 15:30:11 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	copy_new_line(t_files *files, int fd)
{
	FT_(!(files->stage = ft_strdup(files->file[fd])), -1);
	ft_strdel(&files->line);
	FT_(!(files->line = ft_strdup(\
					ft_memset(ft_strchr(files->stage, '\n'), '\0', 1)\
					- ft_strlen(files->stage))), -1);
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
		FT_(!(files->buffer = \
					(char *)malloc(sizeof(char) * BUFF_SIZE + 1)), -1);
		FT_((bytes = read(fd, files->buffer, BUFF_SIZE)) == 0, 0);
		FT_((bytes < 0), -1);
		FT_(!(files->stage = ft_strjoin(\
						files->file[fd], ft_memset(\
							(files->buffer + bytes), '\0', 1) - bytes)), -1);
		ft_strdel(&files->file[fd]);
		FT_(!(files->file[fd] = ft_strdup(files->stage)), -1);
		ft_strdel(&files->stage);
		ft_strdel(&files->buffer);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_files files;

	FT_((fd < 0 || !line || BUFF_SIZE < 1), -1);
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
