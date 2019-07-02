/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/01 15:18:00 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	copy_new_line(t_files *files, int fd)
{
	char	*stage;
	int		nl_index;

	stage = files->file[fd];
	nl_index = ft_strchr(stage, '\n') - stage;
	FT_(!(files->line = ft_strsub(stage, 0, nl_index)), -1);
	FT_(!(files->file[fd] =
		ft_strsub(stage, nl_index + 1, ft_strlen(stage) - nl_index)), -1);
	ft_strdel(&stage);
	return (1);
}

static int	find_new_line(t_files *files, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	long	bytes;
	char	*stage;

	if (!files->file[fd])
		files->file[fd] = ft_strnew(0);
	while (ft_strchr(files->file[fd], '\n') == NULL)
	{
		FT_((bytes = read(fd, buffer, BUFF_SIZE)) == 0, 0);
		buffer[bytes] = '\0';
		FT_(bytes < 0, -1);
		FT_(!(stage = ft_strjoin(files->file[fd], buffer)), -1);
		ft_strdel(&files->file[fd]);
		files->file[fd] = stage;
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
		FT_(!(*line = files.line), -1);
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
