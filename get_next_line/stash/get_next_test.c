/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseperep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:get_next_line/stash/get_next_test.c
/*   Created: 2019/06/17 10:15:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/01 15:18:00 by tcajee           ###   ########.fr       */
=======
/*   Created: 2019/06/30 17:10:59 by kseperep          #+#    #+#             */
/*   Updated: 2019/07/06 04:23:03 by tcajee           ###   ########.fr       */
>>>>>>> e8f0b29e219526aa57baba1a7b124dbee79a0908:get_next_line/get_next_line.c
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

<<<<<<< HEAD:get_next_line/stash/get_next_test.c
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
=======
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
>>>>>>> e8f0b29e219526aa57baba1a7b124dbee79a0908:get_next_line/get_next_line.c
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_arr[1025];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

<<<<<<< HEAD:get_next_line/stash/get_next_test.c
	FT_((fd < 0 || !line || read(fd, NULL, 0) == -1), -1);
	FT_(find_new_line(&files, fd) < 0, -1);
	if (ft_strchr(files.file[fd], '\n') != NULL)
	{
		FT_(copy_new_line(&files, fd) < 0, -1);
		FT_(!(*line = files.line), -1);
	}
	else if (ft_strlen(files.file[fd]) > 0)
=======
	printf("here\n");
	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	if (fd_arr[fd] == NULL)
		fd_arr[fd] = ft_strnew(0);
	while (!(ft_strchr(fd_arr[fd], '\n')))
>>>>>>> e8f0b29e219526aa57baba1a7b124dbee79a0908:get_next_line/get_next_line.c
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
